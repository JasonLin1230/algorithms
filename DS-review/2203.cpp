void del_x(Sqlist &L, int x) {
	int k = 0, i = 0;
	while (i < L.length) {
		if (L.data[i] == x) {
			k++;
		}
		else {
			L.data[i - k] = L.data[i];
		}
		i++;
	}
	L.length = L.length - k;
}