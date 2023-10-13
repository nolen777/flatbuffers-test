workspace(name = "flatbuffers_test")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

#flatbuffers_version = "2.0.8"
#flatbuffers_sha = "80af25a873bebba60067a1529c03edcc5fc5486c3402354c03a80a5279da5dca"

flatbuffers_version = "23.3.3"

flatbuffers_sha = "f8c453bc8392e6bb0f2a4ff1b534238273d7dc9d980177e5d67f6df4c7e4a6a7"

#flatbuffers_version = "2.0.8"
#
#flatbuffers_sha = "80af25a873bebba60067a1529c03edcc5fc5486c3402354c03a80a5279da5dca"

http_archive(
    name = "com_github_google_flatbuffers",
    sha256 = flatbuffers_sha,
    strip_prefix = "flatbuffers-%s" % flatbuffers_version,
    urls = [
        "https://github.com/google/flatbuffers/archive/v%s.zip" % flatbuffers_version,
    ],
)

#
# gtest
#

gtest_commit = "5ab508a01f9eb089207ee87fd547d290da39d015"

gtest_sha = "755f9a39bc7205f5a0c428e920ddad092c33c8a1b46997def3f1d4a82aded6e1"

http_archive(
    name = "com_github_gtest",
    sha256 = gtest_sha,
    strip_prefix = "googletest-%s" % gtest_commit,
    urls = ["https://github.com/google/googletest/archive/%s.zip" % gtest_commit],
)
