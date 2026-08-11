hand_tests:
	cat test_data/ip_filter.tsv | ./build/hw2-ip-filter | md5sum && echo 24e7a7b2270daee89c64d3ca5fb3da1a