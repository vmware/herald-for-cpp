//  Copyright 2020 VMware, Inc.
//  SPDX-License-Identifier: Apache-2.0
//

#ifndef SENSORARRAY_H
#define SENSORARRAY_H

#include "sensor_delegate.h"
#include "sensor.h"
#include "context.h"
#include "payload/payload_data_supplier.h"
#include "datatype/data.h"
#include "datatype/target_identifier.h"
#include "datatype/payload_data.h"

#include <memory>

namespace herald {
  
using namespace datatype;
using namespace payload;

class SensorArray : public Sensor {
public:
  /// Takes ownership of payloadDataSupplier (std::move)
  SensorArray(std::shared_ptr<Context> ctx, std::shared_ptr<PayloadDataSupplier> payloadDataSupplier);
  ~SensorArray();

  // SENSOR ARRAY METHODS
  bool immediateSend(Data data, const TargetIdentifier& targetIdentifier);

  std::shared_ptr<PayloadData> payloadData();

  // SENSOR OVERRIDES 
  void add(std::shared_ptr<SensorDelegate> delegate) override;
  void start() override;
  void stop() override;

private:
  class Impl;
  std::unique_ptr<Impl> mImpl; // PIMPL IDIOM
};




} // end namespace

#endif