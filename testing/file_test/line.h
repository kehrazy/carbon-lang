// Part of the Carbon Language project, under the Apache License v2.0 with LLVM
// Exceptions. See /LICENSE for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef CARBON_TESTING_FILE_TEST_LINE_H_
#define CARBON_TESTING_FILE_TEST_LINE_H_

#include "common/ostream.h"
#include "llvm/ADT/StringRef.h"

namespace Carbon::Testing {

// Interface for lines.
class FileTestLineBase {
 public:
  explicit FileTestLineBase(int line_number) : line_number_(line_number) {}
  virtual ~FileTestLineBase() {}

  // Prints the autoupdated line.
  virtual auto Print(llvm::raw_ostream& out) const -> void = 0;

  virtual auto is_blank() const -> bool = 0;

  auto line_number() const -> int { return line_number_; }

 private:
  int line_number_;
};

// A line in the original file test.
class FileTestLine : public FileTestLineBase {
 public:
  explicit FileTestLine(int line_number, llvm::StringRef line)
      : FileTestLineBase(line_number), line_(line) {}

  auto Print(llvm::raw_ostream& out) const -> void override { out << line_; }

  auto is_blank() const -> bool override { return line_.empty(); }

  auto indent() const -> llvm::StringRef {
    return line_.substr(0, line_.find_first_not_of(" \n"));
  }

 private:
  llvm::StringRef line_;
};

}  // namespace Carbon::Testing

#endif  // CARBON_TESTING_FILE_TEST_LINE_H_
