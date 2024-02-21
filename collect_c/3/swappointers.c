void swap(int *px, int *py);

int main(void) {
	return 0;
}

void swap(int *px, int *py) {
	int temp;

	temp = *px;
	*px = *py;
	*py = temp;
}
