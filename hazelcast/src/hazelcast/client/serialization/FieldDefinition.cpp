//
//  FieldDefinition.cpp
//  Server
//
//  Created by sancar koyunlu on 1/10/13.
//  Copyright (c) 2013 sancar koyunlu. All rights reserved.
//
#include "hazelcast/client/serialization/FieldDefinition.h"
#include "hazelcast/client/serialization/BufferedDataOutput.h"
#include "hazelcast/client/serialization/BufferedDataInput.h"

namespace hazelcast {
    namespace client {
        namespace serialization {

            FieldDefinition::FieldDefinition() {

            };

            FieldDefinition::FieldDefinition(int index, std::string fieldName, FieldType const &type)
            :classId(-1)
            , type(type)
            , fieldName(fieldName)
            , index(index)
            , factoryId(0) {
            };

            FieldDefinition::FieldDefinition(int index, std::string fieldName, FieldType const &type, int factoryId, int classId)
            :classId(classId)
            , type(type)
            , fieldName(fieldName)
            , index(index)
            , factoryId(factoryId) {
            };

            FieldType FieldDefinition::getType() const {
                return type;
            };

            std::string FieldDefinition::getName() const {
                return fieldName;
            };

            int FieldDefinition::getIndex() const {
                return index;
            };

            int FieldDefinition::getFactoryId() const {
                return factoryId;
            }

            int FieldDefinition::getClassId() const {
                return classId;
            };


            void FieldDefinition::writeData(BufferedDataOutput & dataOutput) {
                dataOutput.writeInt(index);
                dataOutput.writeUTF(fieldName);
                dataOutput.writeByte(type.getId());
                dataOutput.writeInt(factoryId);
                dataOutput.writeInt(classId);
            };

            void FieldDefinition::readData(BufferedDataInput & dataInput) {
                index = dataInput.readInt();
                fieldName = dataInput.readUTF();
                type.id = dataInput.readByte();
                factoryId = dataInput.readInt();
                classId = dataInput.readInt();

            };

            bool FieldDefinition::operator ==(const FieldDefinition & other) const {
                if (this == &other) return true;

                if (classId != other.classId) return false;
                if (factoryId != other.factoryId) return false;
                if (index != other.index) return false;
                if (type.getId() != other.type.getId()) return false;
                if (fieldName.compare(other.fieldName)) return false;

                return true;
            };

            bool FieldDefinition::operator !=(const FieldDefinition & other) const {
                return !(*this == other);
            };
        }
    }
}