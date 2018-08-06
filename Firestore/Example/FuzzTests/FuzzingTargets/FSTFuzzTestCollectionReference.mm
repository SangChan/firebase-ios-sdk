/*
 * Copyright 2018 Google
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#import <Foundation/Foundation.h>
#include <cstddef>
#include <cstdint>

#import "Firestore/Example/FuzzTests/FuzzingTargets/FSTFuzzTestCollectionReference.h"
#import "Firestore/Source/Public/FIRCollectionReference.h"
#import "Firestore/Source/Public/FIRDocumentReference.h"

#include "Firestore/core/test/firebase/firestore/testutil/testutil.h"

namespace firebase {
namespace firestore {
namespace fuzzing {

namespace testutil = firebase::firestore::testutil;
namespace util = firebase::firestore::util;

  
int FuzzTestCollectionReference(const uint8_t *data, size_t size) {
  @autoreleasepool {
    NSData *d = [NSData dataWithBytes:data length:size];
    NSString *string = [[NSString alloc] initWithData:d encoding:NSUTF8StringEncoding];

  @try {
    [FIRDocumentReference referenceWithPath:testutil::Resource(nil)
                                  firestore:nil];
  } @catch (...) {
    // Ignore caught exceptions and assertions.
  }

  @try {
    FIRDocumentReference *doc1 = [firestore documentWithPath:string];
  } @catch (...) {
    // Ignore caught exceptions and assertions.
  }
  }
}

}  // namespace fuzzing
}  // namespace firestore
}  // namespace firebase
