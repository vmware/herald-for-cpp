//  Copyright 2020 VMware, Inc.
//  SPDX-License-Identifier: Apache-2.0
//

#ifndef CONTEXT_H
#define CONTEXT_H

#include <iosfwd>
#include <string>

namespace herald {

/**
 * Some platforms require global configuration or static configuration that
 * doesn't map well on to C++ idioms. This class provides an extension capability
 * to allow this linking.
 */
class Context {
public:
  Context() = default;
  virtual ~Context() = default;

  virtual std::ostream& getLoggingSink(const std::string& requestedFor) = 0;
};

/**
 * Default context that just sends logging to stdout
 */
class DefaultContext : public Context {
public:
  DefaultContext() = default;
  ~DefaultContext() = default;

  std::ostream& getLoggingSink(const std::string& requestedFor) override;
};

} // end namespace

#endif