all:
	g++ -o get_mean get_mean.cpp BlobProto.pb.cc `pkg-config --libs --cflags protobuf`

clean:
	rm -rf get_mean
