hand_tests:
	cat test_data/ip_filter.tsv | ./build/hw2-ip-filter | md5sum && echo 1186dd63f9630300053f496d2fc24b51