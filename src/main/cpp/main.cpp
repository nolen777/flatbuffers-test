//
// Created by Dan Crosby on 10/9/23.
//

#include <cstdio>
#include <vector>
#include "src/main/cpp/test_generated.h"

using namespace flatbuffers_test;

int main() {
  printf("Hello, World!\n");

  std::vector<Coords> vec{};
  vec.reserve(10);
  for (int i=5; i<15; i++) {
    vec.emplace_back(i, 15 - i);
  }

  flatbuffers::FlatBufferBuilder fbb;

  auto coordsListOffset = fbb.CreateVectorOfStructs(vec);

  flatbuffers_test::StartingPositionListBuilder startingPositionListBuilder(fbb);
  startingPositionListBuilder.add_positions(coordsListOffset);
  auto startingPositionListOffset = startingPositionListBuilder.Finish();

  flatbuffers_test::HexMapBuilder hexMapBuilder(fbb);
  hexMapBuilder.add_defender_starting_positions(startingPositionListOffset);

  fbb.Finish(hexMapBuilder.Finish());

//  size_t size, offset;
//  auto buffer = fbb.ReleaseRaw(size, offset);
  auto ptr = flatbuffers_test::GetHexMap(fbb.GetBufferPointer());
//  auto ptr = (HexMap*)flatbuffers::GetRoot<HexMap>(buffer);

  for (const Coords* entry : *ptr->defender_starting_positions()->positions()) {
    printf("%d %d\n", entry->row(), entry->column());
  }
}