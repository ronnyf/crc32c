// swift-tools-version: 5.7
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
	name: "crc32c",
	products: [
		.library(
			name: "libcrc32c",
			type: .static,
			targets: ["crc32c"]
		),
		.library(
			name: "dlibcrc32c",
			type: .dynamic,
			targets: ["crc32c"]
		),
	],
	dependencies: [
		.package(url: "https://github.com/ronnyf/googletest.git", .upToNextMajor(from: "1.9.6")),
	],
	targets: [
		.target(
			name: "crc32c",
			path: "./",
			sources: [
				"src/crc32c_arm64.cc",
				"src/crc32c_portable.cc",
				"src/crc32c_sse42.cc",
				"src/crc32c.cc",
			],
			publicHeadersPath: "include",
			cSettings: [
				.headerSearchPath("config"),
			]
		),
		.testTarget(
			name: "crc32Tests",
			dependencies: [
				"crc32c",
				.product(name: "googletest", package: "googletest"),
			],
			path: "src",
			sources: [
				"crc32c_unittest.cc",
				"crc32c_sse42_unittest.cc",
				"crc32c_round_up_unittest.cc",
				"crc32c_read_le_unittest.cc",
				"crc32c_prefetch_unittest.cc",
				"crc32c_portable_unittest.cc",
				"crc32c_arm64_unittest.cc",
			],
			cSettings: [
				.headerSearchPath("../config"),
				.headerSearchPath("../include"),
			],
			linkerSettings: [
				.linkedFramework("XCTest"),
				.linkedFramework("Foundation"),
			]
		),
	],
	cLanguageStandard: .gnu11,
	cxxLanguageStandard: .gnucxx20
)
