# trans-mean
## This is a simple tool, that transform caffe binaryproto file to python npy file.

# USE

protoc --cpp_out=. BlobProto.proto

make

./get_mean mean.binaryproto mean.txt

./get_npy mean.txt mean.npy

rm mean.txt
