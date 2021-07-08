//  Copyright 2021 Herald project contributors
//  SPDX-License-Identifier: Apache-2.0
//

#include "catch.hpp"

#include "herald/herald.h"

#include <utility>
#include <iostream>

using namespace herald::analysis::sampling;
using namespace herald::datatype;

// template <std::size_t Sz>
// struct DummyRSSISource {
//   using value_type = Sample<RSSI>; // allows AnalysisRunner to introspect this class at compile time

//   DummyRSSISource(const std::size_t srcDeviceKey, SampleList<Sample<RSSI>,Sz>&& data) : key(srcDeviceKey), data(std::move(data)) {};
//   ~DummyRSSISource() = default;

//   template <typename RunnerT>
//   void run(int timeTo, RunnerT& runner) {
//     // push through data at default rate
//     for (auto& v: data) {
//       // devList.push(v.taken,v.value); // copy data over (It's unusual taking a SampleList and sending to a SampleList)
//       if (v.taken.secondsSinceUnixEpoch() <= timeTo) {
//         runner.template newSample<RSSI>(key,v);
//       }
//     }
//     runner.run(Date(timeTo));
//   }

// private:
//   std::size_t key;
//   SampleList<Sample<RSSI>,Sz> data;
// };

// struct DummyDistanceDelegate /* : herald::analysis::AnalysisDelegate */ {
//   using value_type = Distance;

//   DummyDistanceDelegate() : lastSampledID(0), distances() {};
//   DummyDistanceDelegate(const DummyDistanceDelegate&) = delete; // copy ctor deleted
//   DummyDistanceDelegate(DummyDistanceDelegate&& other) noexcept : lastSampledID(other.lastSampledID), distances(std::move(other.distances)) {} // move ctor
//   ~DummyDistanceDelegate() {};

//   DummyDistanceDelegate& operator=(DummyDistanceDelegate&& other) noexcept {
//     lastSampledID = other.lastSampledID;
//     std::swap(distances,other.distances);
//     return *this;
//   }

//   // specific override of template
//   void newSample(SampledID sampled, Sample<Distance> sample) {
//     lastSampledID = sampled;
//     distances.push(sample);
//   }

//   void reset() {
//     distances.clear();
//     lastSampledID = 0;
//   }

//   // Test only methods
//   SampledID lastSampled() {
//     return lastSampledID;
//   }

//   const SampleList<Sample<Distance>,25>& samples() {
//     return distances;
//   }

// private:
//   SampledID lastSampledID;
//   SampleList<Sample<Distance>,25> distances;
// };


TEST_CASE("aggregates-gaussian-empty", "[aggregates][gaussian][empty][basic]") {
  SECTION("aggregates-gaussian-empty") {
    herald::analysis::aggregates::Gaussian g;

    REQUIRE(g.reduce() == 0.0);
    REQUIRE(g.model().count() == 0);
    REQUIRE(g.model().min() != 0);
    REQUIRE(g.model().max() != 0);
  }
}

TEST_CASE("aggregates-gaussian-mapreduce", "[aggregates][gaussian][mapreduce][basic]") {
  SECTION("aggregates-gaussian-mapreduce") {
    herald::analysis::aggregates::Gaussian g;
    double sum = 0.0;
    std::size_t count = 0;
    for (std::int8_t i = 0;i < 10; ++i) {
      g.map(herald::analysis::Sample(herald::datatype::Date(0),i));
      sum += i;
      ++count;
      REQUIRE(((g.reduce() == sum / count) || (g.reduce() == 0.0)));
    }
    REQUIRE(g.model().count() == 10);
    REQUIRE(g.model().min() == 0);
    REQUIRE(g.model().max() == 9);
    // g.reduce value test too (in expected range for data given)
    REQUIRE(g.reduce() == sum / count);
  }
}

TEST_CASE("aggregates-gaussian-reset", "[aggregates][gaussian][reset][basic]") {
  SECTION("aggregates-gaussian-reset") {
    herald::analysis::aggregates::Gaussian g;
    g.map(herald::analysis::Sample(herald::datatype::Date(0),5));

    g.reset();

    REQUIRE(g.reduce() == 0.0);
    REQUIRE(g.model().count() == 0);
    REQUIRE(g.model().min() != 0);
    REQUIRE(g.model().max() != 0);
  }
}
