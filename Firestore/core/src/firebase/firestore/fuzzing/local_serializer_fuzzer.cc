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

#include <cstddef>
#include <cstdint>

#include "Firestore/core/src/firebase/firestore/model/database_id.h"
#include "Firestore/core/src/firebase/firestore/remote/serializer.h"
#include "Firestore/core/src/firebase/firestore/local/local_serializer.h"

using firebase::firestore::model::DatabaseId;
using firebase::firestore::remote::Serializer;
using firebase::firestore::local::LocalSerializer;

extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size) {
  
  Serializer remote_serializer{DatabaseId{"project", DatabaseId::kDefault}};
  LocalSerializer serializer{remote_serializer};
  try {
    // Try to decode the received data using the serializer.
    auto val = serializer.DecodeQueryData(data, size);
  } catch (...) {
    // Ignore caught errors and assertions.
  }
  
  try {
    // Try to decode the received data using the serializer.
    auto val = serializer.DecodeMaybeDocument(data, size);
  } catch (...) {
    // Ignore caught errors and assertions.
  }
  
  return 0;
}

