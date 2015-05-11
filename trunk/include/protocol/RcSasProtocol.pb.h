// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: RcSasProtocol.proto

#ifndef PROTOBUF_RcSasProtocol_2eproto__INCLUDED
#define PROTOBUF_RcSasProtocol_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace RcSasProto {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_RcSasProtocol_2eproto();
void protobuf_AssignDesc_RcSasProtocol_2eproto();
void protobuf_ShutdownFile_RcSasProtocol_2eproto();

class AddBusinessEntry;
class UpdateBusinessEntry;
class DeleteBusinessEntry;

// ===================================================================

class AddBusinessEntry : public ::google::protobuf::Message {
 public:
  AddBusinessEntry();
  virtual ~AddBusinessEntry();

  AddBusinessEntry(const AddBusinessEntry& from);

  inline AddBusinessEntry& operator=(const AddBusinessEntry& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const AddBusinessEntry& default_instance();

  void Swap(AddBusinessEntry* other);

  // implements Message ----------------------------------------------

  AddBusinessEntry* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const AddBusinessEntry& from);
  void MergeFrom(const AddBusinessEntry& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required uint32 framework_instance_id = 1;
  inline bool has_framework_instance_id() const;
  inline void clear_framework_instance_id();
  static const int kFrameworkInstanceIdFieldNumber = 1;
  inline ::google::protobuf::uint32 framework_instance_id() const;
  inline void set_framework_instance_id(::google::protobuf::uint32 value);

  // required string entry_ip = 2;
  inline bool has_entry_ip() const;
  inline void clear_entry_ip();
  static const int kEntryIpFieldNumber = 2;
  inline const ::std::string& entry_ip() const;
  inline void set_entry_ip(const ::std::string& value);
  inline void set_entry_ip(const char* value);
  inline void set_entry_ip(const char* value, size_t size);
  inline ::std::string* mutable_entry_ip();
  inline ::std::string* release_entry_ip();
  inline void set_allocated_entry_ip(::std::string* entry_ip);

  // required uint32 entry_port = 3;
  inline bool has_entry_port() const;
  inline void clear_entry_port();
  static const int kEntryPortFieldNumber = 3;
  inline ::google::protobuf::uint32 entry_port() const;
  inline void set_entry_port(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:RcSasProto.AddBusinessEntry)
 private:
  inline void set_has_framework_instance_id();
  inline void clear_has_framework_instance_id();
  inline void set_has_entry_ip();
  inline void clear_has_entry_ip();
  inline void set_has_entry_port();
  inline void clear_has_entry_port();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::std::string* entry_ip_;
  ::google::protobuf::uint32 framework_instance_id_;
  ::google::protobuf::uint32 entry_port_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];

  friend void  protobuf_AddDesc_RcSasProtocol_2eproto();
  friend void protobuf_AssignDesc_RcSasProtocol_2eproto();
  friend void protobuf_ShutdownFile_RcSasProtocol_2eproto();

  void InitAsDefaultInstance();
  static AddBusinessEntry* default_instance_;
};
// -------------------------------------------------------------------

class UpdateBusinessEntry : public ::google::protobuf::Message {
 public:
  UpdateBusinessEntry();
  virtual ~UpdateBusinessEntry();

  UpdateBusinessEntry(const UpdateBusinessEntry& from);

  inline UpdateBusinessEntry& operator=(const UpdateBusinessEntry& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const UpdateBusinessEntry& default_instance();

  void Swap(UpdateBusinessEntry* other);

  // implements Message ----------------------------------------------

  UpdateBusinessEntry* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const UpdateBusinessEntry& from);
  void MergeFrom(const UpdateBusinessEntry& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required uint32 framework_instance_id = 1;
  inline bool has_framework_instance_id() const;
  inline void clear_framework_instance_id();
  static const int kFrameworkInstanceIdFieldNumber = 1;
  inline ::google::protobuf::uint32 framework_instance_id() const;
  inline void set_framework_instance_id(::google::protobuf::uint32 value);

  // required string entry_ip = 2;
  inline bool has_entry_ip() const;
  inline void clear_entry_ip();
  static const int kEntryIpFieldNumber = 2;
  inline const ::std::string& entry_ip() const;
  inline void set_entry_ip(const ::std::string& value);
  inline void set_entry_ip(const char* value);
  inline void set_entry_ip(const char* value, size_t size);
  inline ::std::string* mutable_entry_ip();
  inline ::std::string* release_entry_ip();
  inline void set_allocated_entry_ip(::std::string* entry_ip);

  // required uint32 entry_port = 3;
  inline bool has_entry_port() const;
  inline void clear_entry_port();
  static const int kEntryPortFieldNumber = 3;
  inline ::google::protobuf::uint32 entry_port() const;
  inline void set_entry_port(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:RcSasProto.UpdateBusinessEntry)
 private:
  inline void set_has_framework_instance_id();
  inline void clear_has_framework_instance_id();
  inline void set_has_entry_ip();
  inline void clear_has_entry_ip();
  inline void set_has_entry_port();
  inline void clear_has_entry_port();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::std::string* entry_ip_;
  ::google::protobuf::uint32 framework_instance_id_;
  ::google::protobuf::uint32 entry_port_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];

  friend void  protobuf_AddDesc_RcSasProtocol_2eproto();
  friend void protobuf_AssignDesc_RcSasProtocol_2eproto();
  friend void protobuf_ShutdownFile_RcSasProtocol_2eproto();

  void InitAsDefaultInstance();
  static UpdateBusinessEntry* default_instance_;
};
// -------------------------------------------------------------------

class DeleteBusinessEntry : public ::google::protobuf::Message {
 public:
  DeleteBusinessEntry();
  virtual ~DeleteBusinessEntry();

  DeleteBusinessEntry(const DeleteBusinessEntry& from);

  inline DeleteBusinessEntry& operator=(const DeleteBusinessEntry& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const DeleteBusinessEntry& default_instance();

  void Swap(DeleteBusinessEntry* other);

  // implements Message ----------------------------------------------

  DeleteBusinessEntry* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const DeleteBusinessEntry& from);
  void MergeFrom(const DeleteBusinessEntry& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required uint32 framework_instance_id = 1;
  inline bool has_framework_instance_id() const;
  inline void clear_framework_instance_id();
  static const int kFrameworkInstanceIdFieldNumber = 1;
  inline ::google::protobuf::uint32 framework_instance_id() const;
  inline void set_framework_instance_id(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:RcSasProto.DeleteBusinessEntry)
 private:
  inline void set_has_framework_instance_id();
  inline void clear_has_framework_instance_id();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 framework_instance_id_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_RcSasProtocol_2eproto();
  friend void protobuf_AssignDesc_RcSasProtocol_2eproto();
  friend void protobuf_ShutdownFile_RcSasProtocol_2eproto();

  void InitAsDefaultInstance();
  static DeleteBusinessEntry* default_instance_;
};
// ===================================================================


// ===================================================================

// AddBusinessEntry

// required uint32 framework_instance_id = 1;
inline bool AddBusinessEntry::has_framework_instance_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void AddBusinessEntry::set_has_framework_instance_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void AddBusinessEntry::clear_has_framework_instance_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void AddBusinessEntry::clear_framework_instance_id() {
  framework_instance_id_ = 0u;
  clear_has_framework_instance_id();
}
inline ::google::protobuf::uint32 AddBusinessEntry::framework_instance_id() const {
  return framework_instance_id_;
}
inline void AddBusinessEntry::set_framework_instance_id(::google::protobuf::uint32 value) {
  set_has_framework_instance_id();
  framework_instance_id_ = value;
}

// required string entry_ip = 2;
inline bool AddBusinessEntry::has_entry_ip() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void AddBusinessEntry::set_has_entry_ip() {
  _has_bits_[0] |= 0x00000002u;
}
inline void AddBusinessEntry::clear_has_entry_ip() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void AddBusinessEntry::clear_entry_ip() {
  if (entry_ip_ != &::google::protobuf::internal::kEmptyString) {
    entry_ip_->clear();
  }
  clear_has_entry_ip();
}
inline const ::std::string& AddBusinessEntry::entry_ip() const {
  return *entry_ip_;
}
inline void AddBusinessEntry::set_entry_ip(const ::std::string& value) {
  set_has_entry_ip();
  if (entry_ip_ == &::google::protobuf::internal::kEmptyString) {
    entry_ip_ = new ::std::string;
  }
  entry_ip_->assign(value);
}
inline void AddBusinessEntry::set_entry_ip(const char* value) {
  set_has_entry_ip();
  if (entry_ip_ == &::google::protobuf::internal::kEmptyString) {
    entry_ip_ = new ::std::string;
  }
  entry_ip_->assign(value);
}
inline void AddBusinessEntry::set_entry_ip(const char* value, size_t size) {
  set_has_entry_ip();
  if (entry_ip_ == &::google::protobuf::internal::kEmptyString) {
    entry_ip_ = new ::std::string;
  }
  entry_ip_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* AddBusinessEntry::mutable_entry_ip() {
  set_has_entry_ip();
  if (entry_ip_ == &::google::protobuf::internal::kEmptyString) {
    entry_ip_ = new ::std::string;
  }
  return entry_ip_;
}
inline ::std::string* AddBusinessEntry::release_entry_ip() {
  clear_has_entry_ip();
  if (entry_ip_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = entry_ip_;
    entry_ip_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void AddBusinessEntry::set_allocated_entry_ip(::std::string* entry_ip) {
  if (entry_ip_ != &::google::protobuf::internal::kEmptyString) {
    delete entry_ip_;
  }
  if (entry_ip) {
    set_has_entry_ip();
    entry_ip_ = entry_ip;
  } else {
    clear_has_entry_ip();
    entry_ip_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// required uint32 entry_port = 3;
inline bool AddBusinessEntry::has_entry_port() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void AddBusinessEntry::set_has_entry_port() {
  _has_bits_[0] |= 0x00000004u;
}
inline void AddBusinessEntry::clear_has_entry_port() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void AddBusinessEntry::clear_entry_port() {
  entry_port_ = 0u;
  clear_has_entry_port();
}
inline ::google::protobuf::uint32 AddBusinessEntry::entry_port() const {
  return entry_port_;
}
inline void AddBusinessEntry::set_entry_port(::google::protobuf::uint32 value) {
  set_has_entry_port();
  entry_port_ = value;
}

// -------------------------------------------------------------------

// UpdateBusinessEntry

// required uint32 framework_instance_id = 1;
inline bool UpdateBusinessEntry::has_framework_instance_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void UpdateBusinessEntry::set_has_framework_instance_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void UpdateBusinessEntry::clear_has_framework_instance_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void UpdateBusinessEntry::clear_framework_instance_id() {
  framework_instance_id_ = 0u;
  clear_has_framework_instance_id();
}
inline ::google::protobuf::uint32 UpdateBusinessEntry::framework_instance_id() const {
  return framework_instance_id_;
}
inline void UpdateBusinessEntry::set_framework_instance_id(::google::protobuf::uint32 value) {
  set_has_framework_instance_id();
  framework_instance_id_ = value;
}

// required string entry_ip = 2;
inline bool UpdateBusinessEntry::has_entry_ip() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void UpdateBusinessEntry::set_has_entry_ip() {
  _has_bits_[0] |= 0x00000002u;
}
inline void UpdateBusinessEntry::clear_has_entry_ip() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void UpdateBusinessEntry::clear_entry_ip() {
  if (entry_ip_ != &::google::protobuf::internal::kEmptyString) {
    entry_ip_->clear();
  }
  clear_has_entry_ip();
}
inline const ::std::string& UpdateBusinessEntry::entry_ip() const {
  return *entry_ip_;
}
inline void UpdateBusinessEntry::set_entry_ip(const ::std::string& value) {
  set_has_entry_ip();
  if (entry_ip_ == &::google::protobuf::internal::kEmptyString) {
    entry_ip_ = new ::std::string;
  }
  entry_ip_->assign(value);
}
inline void UpdateBusinessEntry::set_entry_ip(const char* value) {
  set_has_entry_ip();
  if (entry_ip_ == &::google::protobuf::internal::kEmptyString) {
    entry_ip_ = new ::std::string;
  }
  entry_ip_->assign(value);
}
inline void UpdateBusinessEntry::set_entry_ip(const char* value, size_t size) {
  set_has_entry_ip();
  if (entry_ip_ == &::google::protobuf::internal::kEmptyString) {
    entry_ip_ = new ::std::string;
  }
  entry_ip_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* UpdateBusinessEntry::mutable_entry_ip() {
  set_has_entry_ip();
  if (entry_ip_ == &::google::protobuf::internal::kEmptyString) {
    entry_ip_ = new ::std::string;
  }
  return entry_ip_;
}
inline ::std::string* UpdateBusinessEntry::release_entry_ip() {
  clear_has_entry_ip();
  if (entry_ip_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = entry_ip_;
    entry_ip_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void UpdateBusinessEntry::set_allocated_entry_ip(::std::string* entry_ip) {
  if (entry_ip_ != &::google::protobuf::internal::kEmptyString) {
    delete entry_ip_;
  }
  if (entry_ip) {
    set_has_entry_ip();
    entry_ip_ = entry_ip;
  } else {
    clear_has_entry_ip();
    entry_ip_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// required uint32 entry_port = 3;
inline bool UpdateBusinessEntry::has_entry_port() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void UpdateBusinessEntry::set_has_entry_port() {
  _has_bits_[0] |= 0x00000004u;
}
inline void UpdateBusinessEntry::clear_has_entry_port() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void UpdateBusinessEntry::clear_entry_port() {
  entry_port_ = 0u;
  clear_has_entry_port();
}
inline ::google::protobuf::uint32 UpdateBusinessEntry::entry_port() const {
  return entry_port_;
}
inline void UpdateBusinessEntry::set_entry_port(::google::protobuf::uint32 value) {
  set_has_entry_port();
  entry_port_ = value;
}

// -------------------------------------------------------------------

// DeleteBusinessEntry

// required uint32 framework_instance_id = 1;
inline bool DeleteBusinessEntry::has_framework_instance_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void DeleteBusinessEntry::set_has_framework_instance_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void DeleteBusinessEntry::clear_has_framework_instance_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void DeleteBusinessEntry::clear_framework_instance_id() {
  framework_instance_id_ = 0u;
  clear_has_framework_instance_id();
}
inline ::google::protobuf::uint32 DeleteBusinessEntry::framework_instance_id() const {
  return framework_instance_id_;
}
inline void DeleteBusinessEntry::set_framework_instance_id(::google::protobuf::uint32 value) {
  set_has_framework_instance_id();
  framework_instance_id_ = value;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace RcSasProto

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_RcSasProtocol_2eproto__INCLUDED