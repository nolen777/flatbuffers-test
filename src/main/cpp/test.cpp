//
// Created by Dan Crosby on 10/12/23.
//

#include "gtest/gtest.h"

#include <cstdio>
#include <vector>
#include "src/main/cpp/test_generated.h"

using namespace flatbuffers_test;

class DummyTest : public ::testing::Test {};

using std::vector;

TEST_F(DummyTest, BuildBasicMap_hasCorrectStartingPositions) {
  const vector<Coords> defenderStartingPositions = { Coords(2, 3), Coords(2, 4), Coords(2, 5) };

  flatbuffers::FlatBufferBuilder fbb;

  auto coordsListOffset = fbb.CreateVectorOfStructs(defenderStartingPositions);

  flatbuffers_test::HexMapBuilder hexMapBuilder(fbb);
  hexMapBuilder.add_defender_starting_positions(coordsListOffset);

  fbb.Finish(hexMapBuilder.Finish());
  auto hexMap = flatbuffers_test::GetHexMap(fbb.GetBufferPointer());

  EXPECT_EQ(defenderStartingPositions.size(), hexMap->defender_starting_positions()->size());

  for (const Coords* entry : *hexMap->defender_starting_positions()) {
    printf("%d %d\n", entry->row(), entry->column());
  }

  for (int i = 0; i < defenderStartingPositions.size(); i++) {
    EXPECT_EQ(
        defenderStartingPositions[i].row(),
        hexMap->defender_starting_positions()->Get(i)->row());
    EXPECT_EQ(
        defenderStartingPositions[i].column(),
        hexMap->defender_starting_positions()->Get(i)->column());
  }
}