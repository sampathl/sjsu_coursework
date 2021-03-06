# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: group_chat.proto

import sys
_b=sys.version_info[0]<3 and (lambda x:x) or (lambda x:x.encode('latin1'))
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()




DESCRIPTOR = _descriptor.FileDescriptor(
  name='group_chat.proto',
  package='grpc',
  syntax='proto3',
  serialized_options=None,
  serialized_pb=_b('\n\x10group_chat.proto\x12\x04grpc\"\x07\n\x05\x42lank\"%\n\x07Message\x12\x0c\n\x04name\x18\x01 \x01(\t\x12\x0c\n\x04note\x18\x02 \x01(\t\"\x14\n\x04User\x12\x0c\n\x04name\x18\x01 \x01(\t2\x8b\x01\n\nChatServer\x12-\n\x0bNew_messege\x12\r.grpc.Message\x1a\r.grpc.Message0\x01\x12)\n\x0bSend_messge\x12\r.grpc.Message\x1a\x0b.grpc.Blank\x12#\n\x08New_user\x12\n.grpc.User\x1a\x0b.grpc.Blankb\x06proto3')
)




_BLANK = _descriptor.Descriptor(
  name='Blank',
  full_name='grpc.Blank',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=26,
  serialized_end=33,
)


_MESSAGE = _descriptor.Descriptor(
  name='Message',
  full_name='grpc.Message',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='name', full_name='grpc.Message.name', index=0,
      number=1, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=_b("").decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='note', full_name='grpc.Message.note', index=1,
      number=2, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=_b("").decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=35,
  serialized_end=72,
)


_USER = _descriptor.Descriptor(
  name='User',
  full_name='grpc.User',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='name', full_name='grpc.User.name', index=0,
      number=1, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=_b("").decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=74,
  serialized_end=94,
)

DESCRIPTOR.message_types_by_name['Blank'] = _BLANK
DESCRIPTOR.message_types_by_name['Message'] = _MESSAGE
DESCRIPTOR.message_types_by_name['User'] = _USER
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

Blank = _reflection.GeneratedProtocolMessageType('Blank', (_message.Message,), dict(
  DESCRIPTOR = _BLANK,
  __module__ = 'group_chat_pb2'
  # @@protoc_insertion_point(class_scope:grpc.Blank)
  ))
_sym_db.RegisterMessage(Blank)

Message = _reflection.GeneratedProtocolMessageType('Message', (_message.Message,), dict(
  DESCRIPTOR = _MESSAGE,
  __module__ = 'group_chat_pb2'
  # @@protoc_insertion_point(class_scope:grpc.Message)
  ))
_sym_db.RegisterMessage(Message)

User = _reflection.GeneratedProtocolMessageType('User', (_message.Message,), dict(
  DESCRIPTOR = _USER,
  __module__ = 'group_chat_pb2'
  # @@protoc_insertion_point(class_scope:grpc.User)
  ))
_sym_db.RegisterMessage(User)



_CHATSERVER = _descriptor.ServiceDescriptor(
  name='ChatServer',
  full_name='grpc.ChatServer',
  file=DESCRIPTOR,
  index=0,
  serialized_options=None,
  serialized_start=97,
  serialized_end=236,
  methods=[
  _descriptor.MethodDescriptor(
    name='New_messege',
    full_name='grpc.ChatServer.New_messege',
    index=0,
    containing_service=None,
    input_type=_MESSAGE,
    output_type=_MESSAGE,
    serialized_options=None,
  ),
  _descriptor.MethodDescriptor(
    name='Send_messge',
    full_name='grpc.ChatServer.Send_messge',
    index=1,
    containing_service=None,
    input_type=_MESSAGE,
    output_type=_BLANK,
    serialized_options=None,
  ),
  _descriptor.MethodDescriptor(
    name='New_user',
    full_name='grpc.ChatServer.New_user',
    index=2,
    containing_service=None,
    input_type=_USER,
    output_type=_BLANK,
    serialized_options=None,
  ),
])
_sym_db.RegisterServiceDescriptor(_CHATSERVER)

DESCRIPTOR.services_by_name['ChatServer'] = _CHATSERVER

# @@protoc_insertion_point(module_scope)
