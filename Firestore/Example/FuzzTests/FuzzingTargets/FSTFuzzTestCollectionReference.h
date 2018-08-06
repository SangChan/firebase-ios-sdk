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

#ifndef FIRESTORE_EXAMPLE_FUZZTESTS_FUZZINGTARGETS_FSTFUZZTESTCOLLECTIONREFERENCE_H_
#define FIRESTORE_EXAMPLE_FUZZTESTS_FUZZINGTARGETS_FSTFUZZTESTCOLLECTIONREFERENCE_H_

#import <Foundation/Foundation.h>
#include <string>

namespace firebase {
namespace firestore {
namespace fuzzing {

// Returns the location of the CollectionReference dictionary file.
inline std::string GetCollectionReferenceDictionaryLocation(std::string resources_location) {
  return resources_location + "/CollectionReference/collectionreference.dictionary";
}

// Returns the location of the CollectionReference corpus.
inline std::string GetCollectionReferenceCorpusLocation() {
  return resources_location + "/CollectionReference/Corpus";
}

// Fuzz-test creating collection reference.
int FuzzTestCollectionReference(const uint8_t *data, size_t size);

}  // namespace fuzzing
}  // namespace firestore
}  // namespace firebase

#endif  // FIRESTORE_EXAMPLE_FUZZTESTS_FUZZINGTARGETS_FSTFUZZTESTCOLLECTIONREFERENCE_H_
