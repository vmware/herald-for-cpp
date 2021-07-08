//  Copyright 2020-2021 Herald Project Contributors
//  SPDX-License-Identifier: Apache-2.0
//

#ifndef HERALD_PLACENAME_LOCATION_REFERENCE_H
#define HERALD_PLACENAME_LOCATION_REFERENCE_H

#include "location_reference.h"

namespace herald {
namespace datatype {

struct PlacenameLocationReference : public LocationReference {
  PlacenameLocationReference(std::string n) : LocationReference(), name(n) { };
  ~PlacenameLocationReference() = default;
  
  std::string name;

  std::string description() {
    return "PLACE(name=" + name + ")";
  }
};


} // end namespace
} // end namespace

#endif