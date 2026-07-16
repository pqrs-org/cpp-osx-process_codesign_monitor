[![Build Status](https://github.com/pqrs-org/cpp-osx-process_codesign_monitor/workflows/CI/badge.svg)](https://github.com/pqrs-org/cpp-osx-process_codesign_monitor/actions)
[![License](https://img.shields.io/badge/license-Boost%20Software%20License-blue.svg)](https://github.com/cpp-osx-process_codesign_monitor/blob/main/LICENSE.md)

# cpp-osx-process_codesign_monitor

A header-only C++ library for macOS that periodically verifies the code-signing Team ID of a process.

## Requirements

cpp-osx-process_codesign_monitor depends on the following libraries.

- [Nod](https://github.com/fr00b0/nod)
- [pqrs::dispatcher](https://github.com/pqrs-org/cpp-dispatcher)
- [pqrs::osx::codesign](https://github.com/pqrs-org/cpp-osx-codesign)

## Install

Copy `include/pqrs` and `vendor/vendor/include` directories into your include directory.
