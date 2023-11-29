#include <iostream>

class SortStrategy {
	public:
		virtual void sort(int arr[], int size) = 0;
		virtual ~SortStrategy() {}
};

class BubbleSort : public SortStrategy {
	public:
		void sort(int arr[], int size) {
			std::cout << "BubbleSort" << std::endl;
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size - 1; j++) {
					if (arr[j] > arr[j + 1]) {
						int temp = arr[j];
						arr[j] = arr[j + 1];
						arr[j + 1] = temp;
					}
				}
			}

		}
};

class QuickSort : public SortStrategy {
	public:
		void sort(int arr[], int size) {
			std::cout << "QuickSort" << std::endl;
			quickSort(arr, 0, size - 1);
		}
		void quickSort(int arr[], int left, int right) {
			int i = left;
			int j = right;
			int pivot = arr[(left + right) / 2];

			while (i <= j) {
				while (arr[i] < pivot) {
					i++;
				}
				while (arr[j] > pivot) {
					j--;
				}
				if (i <= j) {
					int temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
					i++;
					j--;
				}
			}

			if (left < j) {
				quickSort(arr, left, j);
			}
			if (i < right) {
				quickSort(arr, i, right);
			}
		}
};

class Sorter {
	private:
		SortStrategy* strategy;

	public:
		Sorter(SortStrategy* strategy) : strategy(strategy) {}

		void setStrategy(SortStrategy* strate) {
			strategy = strate;
		}

		void performSort(int arr[], int size) {
			strategy->sort(arr, size);
		}
};

int main(void)
{
	int arr[] = {4, 2, 7, 1, 5};
	int size = sizeof(arr) / sizeof(arr[0]);

	BubbleSort bubbleSort;
	QuickSort quickSort;

	Sorter sorter(&bubbleSort);
	// sorter.performSort(arr, size);

	sorter.setStrategy(&quickSort);
	sorter.performSort(arr, size);


	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << std::endl;
	}

	return 0;
}
