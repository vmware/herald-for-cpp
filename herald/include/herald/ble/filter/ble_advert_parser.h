//  Copyright 2020-2021 Herald Project Contributors
//  SPDX-License-Identifier: Apache-2.0
//

#ifndef HERALD_BLE_ADVERT_PARSER_H
#define HERALD_BLE_ADVERT_PARSER_H

#include "ble_advert_types.h"

#include <vector>

namespace herald {
namespace ble {
namespace filter {

namespace BLEAdvertParser {

// Note the below should NOT be declared static, as they are PUBLIC API methods

// High level parsing functions

std::vector<BLEAdvertSegment> extractSegments(const Data& raw, std::size_t offset) noexcept;


// Parse result extraction functions

bool extractTxPower(const std::vector<BLEAdvertSegment>& segments, std::uint8_t& into) noexcept;
std::vector<Data> extractHeraldManufacturerData(const std::vector<BLEAdvertManufacturerData>& manuData) noexcept;
std::vector<BLEAdvertManufacturerData> extractManufacturerData(const std::vector<BLEAdvertSegment>& segments) noexcept;
std::vector<BLEAdvertAppleManufacturerSegment> extractAppleManufacturerSegments(const std::vector<BLEAdvertManufacturerData>& manuData) noexcept;

// std::vector<BLEAdvertServiceData> extractServiceUUID128Data(std::vector<BLEAdvertSegment> segments) noexcept;

// Low level utility functions
// Exposed in API to allow others to use them

Data subDataBigEndian(const Data& data, std::size_t offset, std::size_t length) noexcept;
Data subDataLittleEndian(const Data& data, std::size_t offset, std::size_t length) noexcept;

}

}
}
}

#endif