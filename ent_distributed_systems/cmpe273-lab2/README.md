# cmpe273-lab2
Lab2 assignment docs for course CMPE273
The lab was performed on windows 10, python can be accessed in CMD(admin) using "py" (instead of python3)
Instructions:
upgrade your pip : py -m pip install --upgrade pip
install gRPC : py -m pip install grpcio
install gRPC tools : py -m pip install grpcio-tools googleapis-common-protos

now navigate to proto folder located at (grpc\examples\protos)

add the file "calculator.proto" in the folder
move to the python folder located at (grpc\examples\python) and create a director named Calculator and move into the folder.

once in the folder run the following command to generate  gRPC code associated with "calculator.proto":
      py -m grpc_tools.protoc -I../../protos --python_out=. --grpc_python_out=. ../../protos/calculator.proto

This will generate "calculator_pb2_grpc.py" & "calculator_pb2,py" in the folder you are in.
copy the "calculator_client.py" & "calculator_server.py" into the folder
now run the server script in one CMD prompt and then client script in another to get and summation result.

# references : https://grpc.io/docs/quickstart/python.html#install-grpc-tools
               https://github.com/grpc/grpc
