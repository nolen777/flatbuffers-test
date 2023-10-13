workspace(name = "flatbuffers_test")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

#flatbuffers_version = "2.0.8"
#flatbuffers_sha = "80af25a873bebba60067a1529c03edcc5fc5486c3402354c03a80a5279da5dca"

# FAIL:
flatbuffers_version = "72aa85a759e997d68b0ff25d16f5ad27fea045ae"

# SUCCESS:
#flatbuffers_version = "bfceebb7fb5fb6a8b12471022aa9e3e519c18412"

http_archive(
    name = "com_github_google_flatbuffers",
    strip_prefix = "flatbuffers-%s" % flatbuffers_version,
    urls = [
        "https://github.com/google/flatbuffers/archive/%s.zip" % flatbuffers_version,
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
