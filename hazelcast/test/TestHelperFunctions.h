/*
 * Copyright (c) 2008-2015, Hazelcast, Inc. All Rights Reserved.
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
//
// Created by sancar koyunlu on 15/05/14.
//


#ifndef HAZELCAST_TestHelperFunctions
#define HAZELCAST_TestHelperFunctions

#define ASSERT_EVENTUALLY( CONDITION, ... ) do{     \
            for(int i = 0 ; i < 60 ; i++ ) {        \
                util::sleep(2);                     \
                if(i == 59){                        \
                    CONDITION(__VA_ARGS__);         \
                }                                   \
                try{                                \
                    CONDITION(__VA_ARGS__);         \
                    break;                          \
                }catch(iTestException ignored){     \
                }                                   \
            }                                       \
      }while(0)                                     \


#endif //HAZELCAST_TestHelperFunctions