/*
 * Copyright (c) 2008-2020, Hazelcast, Inc. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <memory>

#include "hazelcast/client/serialization/pimpl/Data.h"
#include "hazelcast/client/topic/Message.h"
#include "hazelcast/client/Member.h"
#include "hazelcast/util/HazelcastDll.h"

#if  defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64)
#pragma warning(push)
#pragma warning(disable: 4251) //for dll export
#endif

namespace hazelcast {
    namespace client {
        namespace topic {
            namespace impl {
                namespace reliable {
                    class HAZELCAST_API ReliableTopicMessage {
                        friend struct serialization::hz_serializer<topic::impl::reliable::ReliableTopicMessage>;
                    public:
                        ReliableTopicMessage();

                        ReliableTopicMessage(serialization::pimpl::Data &&payloadData, std::unique_ptr<Address> address);

                        std::chrono::system_clock::time_point getPublishTime() const;

                        const boost::optional<Address> &getPublisherAddress() const;

                        serialization::pimpl::Data &getPayload();
                    private:
                        std::chrono::system_clock::time_point publishTime;
                        boost::optional<Address> publisherAddress;
                        serialization::pimpl::Data payload;
                    };
                }
            }
        }
        namespace serialization {
            template<>
            struct hz_serializer<topic::impl::reliable::ReliableTopicMessage> : public identified_data_serializer {
                static constexpr int32_t F_ID = -18;
                static constexpr int32_t RELIABLE_TOPIC_MESSAGE = 2;

                static int32_t getFactoryId();

                static int32_t getClassId();

                static void writeData(const topic::impl::reliable::ReliableTopicMessage &object, ObjectDataOutput &out);

                static topic::impl::reliable::ReliableTopicMessage readData(ObjectDataInput &in);
            };
        }
    }
}

#if  defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64)
#pragma warning(pop)
#endif


