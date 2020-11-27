/**
 * Autogenerated by Thrift Compiler (0.13.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "remote_controller_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace hazelcast {
namespace client {
namespace test {
namespace remote {

int _kLangValues[] = { Lang::JAVASCRIPT, Lang::GROOVY, Lang::PYTHON, Lang::RUBY };
const char* _kLangNames[] = { "JAVASCRIPT", "GROOVY", "PYTHON", "RUBY" };
const std::map<int, const char*> _Lang_VALUES_TO_NAMES(
  ::apache::thrift::TEnumIterator(4, _kLangValues, _kLangNames),
  ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream&
operator<<(std::ostream& out, const Lang::type& val)
{
    std::map<int, const char*>::const_iterator it = _Lang_VALUES_TO_NAMES.find(val);
    if (it != _Lang_VALUES_TO_NAMES.end()) {
        out << it->second;
    } else {
        out << static_cast<int>(val);
    }
    return out;
}

std::string
to_string(const Lang::type& val)
{
    std::map<int, const char*>::const_iterator it = _Lang_VALUES_TO_NAMES.find(val);
    if (it != _Lang_VALUES_TO_NAMES.end()) {
        return std::string(it->second);
    } else {
        return std::to_string(static_cast<int>(val));
    }
}

Cluster::~Cluster() noexcept {}

void
Cluster::__set_id(const std::string& val)
{
    this->id = val;
}
std::ostream&
operator<<(std::ostream& out, const Cluster& obj)
{
    obj.printTo(out);
    return out;
}

uint32_t
Cluster::read(::apache::thrift::protocol::TProtocol* iprot)
{

    ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;

    while (true) {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        switch (fid) {
            case 1:
                if (ftype == ::apache::thrift::protocol::T_STRING) {
                    xfer += iprot->readString(this->id);
                    this->__isset.id = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            default:
                xfer += iprot->skip(ftype);
                break;
        }
        xfer += iprot->readFieldEnd();
    }

    xfer += iprot->readStructEnd();

    return xfer;
}

uint32_t
Cluster::write(::apache::thrift::protocol::TProtocol* oprot) const
{
    uint32_t xfer = 0;
    ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
    xfer += oprot->writeStructBegin("Cluster");

    xfer += oprot->writeFieldBegin("id", ::apache::thrift::protocol::T_STRING, 1);
    xfer += oprot->writeString(this->id);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    return xfer;
}

void
swap(Cluster& a, Cluster& b)
{
    using ::std::swap;
    swap(a.id, b.id);
    swap(a.__isset, b.__isset);
}

Cluster::Cluster(const Cluster& other0)
{
    id = other0.id;
    __isset = other0.__isset;
}
Cluster&
Cluster::operator=(const Cluster& other1)
{
    id = other1.id;
    __isset = other1.__isset;
    return *this;
}
void
Cluster::printTo(std::ostream& out) const
{
    using ::apache::thrift::to_string;
    out << "Cluster(";
    out << "id=" << to_string(id);
    out << ")";
}

Member::~Member() noexcept {}

void
Member::__set_uuid(const std::string& val)
{
    this->uuid = val;
}

void
Member::__set_host(const std::string& val)
{
    this->host = val;
}

void
Member::__set_port(const int32_t val)
{
    this->port = val;
}
std::ostream&
operator<<(std::ostream& out, const Member& obj)
{
    obj.printTo(out);
    return out;
}

uint32_t
Member::read(::apache::thrift::protocol::TProtocol* iprot)
{

    ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;

    while (true) {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        switch (fid) {
            case 1:
                if (ftype == ::apache::thrift::protocol::T_STRING) {
                    xfer += iprot->readString(this->uuid);
                    this->__isset.uuid = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 2:
                if (ftype == ::apache::thrift::protocol::T_STRING) {
                    xfer += iprot->readString(this->host);
                    this->__isset.host = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 3:
                if (ftype == ::apache::thrift::protocol::T_I32) {
                    xfer += iprot->readI32(this->port);
                    this->__isset.port = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            default:
                xfer += iprot->skip(ftype);
                break;
        }
        xfer += iprot->readFieldEnd();
    }

    xfer += iprot->readStructEnd();

    return xfer;
}

uint32_t
Member::write(::apache::thrift::protocol::TProtocol* oprot) const
{
    uint32_t xfer = 0;
    ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
    xfer += oprot->writeStructBegin("Member");

    xfer += oprot->writeFieldBegin("uuid", ::apache::thrift::protocol::T_STRING, 1);
    xfer += oprot->writeString(this->uuid);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("host", ::apache::thrift::protocol::T_STRING, 2);
    xfer += oprot->writeString(this->host);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("port", ::apache::thrift::protocol::T_I32, 3);
    xfer += oprot->writeI32(this->port);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    return xfer;
}

void
swap(Member& a, Member& b)
{
    using ::std::swap;
    swap(a.uuid, b.uuid);
    swap(a.host, b.host);
    swap(a.port, b.port);
    swap(a.__isset, b.__isset);
}

Member::Member(const Member& other2)
{
    uuid = other2.uuid;
    host = other2.host;
    port = other2.port;
    __isset = other2.__isset;
}
Member&
Member::operator=(const Member& other3)
{
    uuid = other3.uuid;
    host = other3.host;
    port = other3.port;
    __isset = other3.__isset;
    return *this;
}
void
Member::printTo(std::ostream& out) const
{
    using ::apache::thrift::to_string;
    out << "member(";
    out << "uuid=" << to_string(uuid);
    out << ", "
        << "host=" << to_string(host);
    out << ", "
        << "port=" << to_string(port);
    out << ")";
}

Response::~Response() noexcept {}

void
Response::__set_success(const bool val)
{
    this->success = val;
}

void
Response::__set_message(const std::string& val)
{
    this->message = val;
}

void
Response::__set_result(const std::string& val)
{
    this->result = val;
}
std::ostream&
operator<<(std::ostream& out, const Response& obj)
{
    obj.printTo(out);
    return out;
}

uint32_t
Response::read(::apache::thrift::protocol::TProtocol* iprot)
{

    ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;

    while (true) {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        switch (fid) {
            case 1:
                if (ftype == ::apache::thrift::protocol::T_BOOL) {
                    xfer += iprot->readBool(this->success);
                    this->__isset.success = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 2:
                if (ftype == ::apache::thrift::protocol::T_STRING) {
                    xfer += iprot->readString(this->message);
                    this->__isset.message = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 3:
                if (ftype == ::apache::thrift::protocol::T_STRING) {
                    xfer += iprot->readBinary(this->result);
                    this->__isset.result = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            default:
                xfer += iprot->skip(ftype);
                break;
        }
        xfer += iprot->readFieldEnd();
    }

    xfer += iprot->readStructEnd();

    return xfer;
}

uint32_t
Response::write(::apache::thrift::protocol::TProtocol* oprot) const
{
    uint32_t xfer = 0;
    ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
    xfer += oprot->writeStructBegin("Response");

    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_BOOL, 1);
    xfer += oprot->writeBool(this->success);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("message", ::apache::thrift::protocol::T_STRING, 2);
    xfer += oprot->writeString(this->message);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("result", ::apache::thrift::protocol::T_STRING, 3);
    xfer += oprot->writeBinary(this->result);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    return xfer;
}

void
swap(Response& a, Response& b)
{
    using ::std::swap;
    swap(a.success, b.success);
    swap(a.message, b.message);
    swap(a.result, b.result);
    swap(a.__isset, b.__isset);
}

Response::Response(const Response& other4)
{
    success = other4.success;
    message = other4.message;
    result = other4.result;
    __isset = other4.__isset;
}
Response&
Response::operator=(const Response& other5)
{
    success = other5.success;
    message = other5.message;
    result = other5.result;
    __isset = other5.__isset;
    return *this;
}
void
Response::printTo(std::ostream& out) const
{
    using ::apache::thrift::to_string;
    out << "Response(";
    out << "success=" << to_string(success);
    out << ", "
        << "message=" << to_string(message);
    out << ", "
        << "result=" << to_string(result);
    out << ")";
}

ServerException::~ServerException() noexcept {}

void
ServerException::__set_message(const std::string& val)
{
    this->message = val;
}
std::ostream&
operator<<(std::ostream& out, const ServerException& obj)
{
    obj.printTo(out);
    return out;
}

uint32_t
ServerException::read(::apache::thrift::protocol::TProtocol* iprot)
{

    ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;

    while (true) {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        switch (fid) {
            case 1:
                if (ftype == ::apache::thrift::protocol::T_STRING) {
                    xfer += iprot->readString(this->message);
                    this->__isset.message = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            default:
                xfer += iprot->skip(ftype);
                break;
        }
        xfer += iprot->readFieldEnd();
    }

    xfer += iprot->readStructEnd();

    return xfer;
}

uint32_t
ServerException::write(::apache::thrift::protocol::TProtocol* oprot) const
{
    uint32_t xfer = 0;
    ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
    xfer += oprot->writeStructBegin("ServerException");

    xfer += oprot->writeFieldBegin("message", ::apache::thrift::protocol::T_STRING, 1);
    xfer += oprot->writeString(this->message);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    return xfer;
}

void
swap(ServerException& a, ServerException& b)
{
    using ::std::swap;
    swap(a.message, b.message);
    swap(a.__isset, b.__isset);
}

ServerException::ServerException(const ServerException& other6)
  : TException()
{
    message = other6.message;
    __isset = other6.__isset;
}
ServerException&
ServerException::operator=(const ServerException& other7)
{
    message = other7.message;
    __isset = other7.__isset;
    return *this;
}
void
ServerException::printTo(std::ostream& out) const
{
    using ::apache::thrift::to_string;
    out << "ServerException(";
    out << "message=" << to_string(message);
    out << ")";
}

const char*
ServerException::what() const noexcept
{
    try {
        std::stringstream ss;
        ss << "TException - service has thrown: " << *this;
        this->thriftTExceptionMessageHolder_ = ss.str();
        return this->thriftTExceptionMessageHolder_.c_str();
    } catch (const std::exception&) {
        return "TException - service has thrown: ServerException";
    }
}

} // namespace remote
} // namespace test
} // namespace client
} // namespace hazelcast
