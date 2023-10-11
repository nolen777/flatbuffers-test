//
// Created by Dan Crosby on 10/9/23.
//

#include <cstdio>
#include <vector>
#include "src/main/cpp/test_generated.h"

using namespace flatbuffers_test;

int main() {
  printf("Hello, World!\n");

  std::vector<TestStruct> vec{};
  for (int i=1; i<10; i++) {
    TestStruct ts;
    ts.mutate_value(i);
    vec.push_back(ts);
  }

  flatbuffers::FlatBufferBuilder fbb;

  auto structsOffset = fbb.CreateVectorOfStructs(vec);

  flatbuffers_test::TestTableBuilder ttb(fbb);
  ttb.add_values(structsOffset);

  auto testTableOffset = ttb.Finish();
  fbb.Finish(testTableOffset);

  size_t size, offset;
  auto buffer = fbb.ReleaseRaw(size, offset);
  auto ptr = (TestTable*)flatbuffers::GetRoot<TestTable>(buffer + offset);

  for (const TestStruct* entry : *ptr->values()) {
    printf("%d\n", entry->value());
  }
}