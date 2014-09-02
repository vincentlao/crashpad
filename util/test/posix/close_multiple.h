// Copyright 2014 The Crashpad Authors. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef CRASHPAD_UTIL_TEST_POSIX_CLOSE_MULTIPLE_H_
#define CRASHPAD_UTIL_TEST_POSIX_CLOSE_MULTIPLE_H_

namespace crashpad {

//! \brief Close multiple file descriptors or mark them close-on-exec.
//!
//! This is similar to the BSD/Solaris-style `closefrom()` routine, which closes
//! all open file descriptors equal to or higher than its \a fd argument. This
//! function must not be called while other threads are active. It is intended
//! to be used in a child process created by `fork()`, prior to calling an
//! `exec()`-family function. This guarantees that a (possibly untrustworthy)
//! child process does not inherit file descriptors that it has no need for.
//!
//! Unlike the BSD function, this function may not close file descriptors
//! immediately, but may instead mark them as close-on-exec. The actual behavior
//! chosen is specific to the operating system. On Mac OS X, file descriptors
//! are marked close-on-exec instead of being closed outright in order to avoid
//! raising `EXC_GUARD` exceptions for guarded file descriptors that are
//! protected against `close()`.
//!
//! \param[in] fd The lowest file descriptor to close or set as close-on-exec.
void CloseMultipleNowOrOnExec(int fd);

}  // namespace crashpad

#endif  // CRASHPAD_UTIL_TEST_POSIX_CLOSE_MULTIPLE_H_
