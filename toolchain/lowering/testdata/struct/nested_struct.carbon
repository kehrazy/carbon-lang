// Part of the Carbon Language project, under the Apache License v2.0 with LLVM
// Exceptions. See /LICENSE for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
// AUTOUPDATE

fn Run() -> i32 {
  {.b = {.a: i32}};
  return 0;
}

// CHECK:STDOUT: ; ModuleID = 'nested_struct.carbon'
// CHECK:STDOUT: source_filename = "nested_struct.carbon"
// CHECK:STDOUT:
// CHECK:STDOUT: %type = type {}
// CHECK:STDOUT:
// CHECK:STDOUT: define i32 @Run() {
// CHECK:STDOUT:   %struct = alloca { %type }, align 8
// CHECK:STDOUT:   %b = getelementptr inbounds { %type }, ptr %struct, i32 0, i32 0
// CHECK:STDOUT:   store %type zeroinitializer, ptr %b, align 1
// CHECK:STDOUT:   ret i32 0
// CHECK:STDOUT: }
