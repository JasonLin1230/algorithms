bool Del_Min(SqList &L, int &min) {
	if (L.length < 1) {
		return false;
	}
	min = L.data[0];
	int loc = 0;
	for (int i = 1; i < L.length < i++) {
		if (L[i] < min) {
			min = L.data[i];
			loc = i;
		}
	}
	L.data[loc] = L.data[L.length - 1];
	L.length--;
	return true;
}