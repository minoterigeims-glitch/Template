

#include <iostream>
#include<windows.h>

using namespace std;

template <typename T>
T FindMax(T arr[], int size) {
	T max = arr[0];
	for (int i = 1;i < size;i++) {
		if (max < arr[i]) {
			max= arr[i];
		}
	}
	return max;
}
template <typename T>
T FindMin(T arr[], int size) {
	T min = arr[0];
	for (int i = 1;i < size;i++) {
		if (min > arr[i]) {
			min = arr[i];
		}
	}
	return min;
}
template <typename T>
void SortArray(T arr[], int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				T temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
    
}
template <typename T>
int BinarySearch(T arr[], int size, T key) {
	int left = 0;
	int right = size - 1;
	int mid;
	while (left <= right) {
		mid = left + (right - left) / 2;

		if (arr[mid] == key) {
			return mid;
		}
		else if (arr[mid] < key) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

}
template <typename T>
void ReplaceElement(T arr[], int size, int index, T value) {
	if (index >= 0 && index < size) {
		arr[index] = value;
	}
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    

    int size;

    cout << "Введіть розмір масиву: ";
    cin >> size;

    if (size <= 0) {
        cout << "Некоректний розмір масиву!" << endl;
        return 0;
    }

    int* arr = new int[size];

    cout << "Введіть елементи масиву:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }
    cout << endl;

    int у;
    int index;
    int value;
    do {
        cout << "==================== МЕНЮ ====================" << endl;
        cout << "1. Знайти максимум" << endl;
        cout << "2. Знайти мінімум" << endl;
        cout << "3. Відсортувати масив" << endl;
        cout << "4. Двійковий пошук" << endl;
        cout << "5. Замінити елемент" << endl;
        cout << "6. Вивести масив" << endl;
        cout << "0. Вихід" << endl;

        cout << "Ваш вибір: ";
        cin >> у;

        switch (у) {
        case 1:
            cout << "Максимум: " << FindMax(arr, size) << endl;
            break;

        case 2:
            cout << "Мінімум: " << FindMin(arr, size) << endl;
            break;

        case 3:
            SortArray(arr, size);
            cout << "Масив відсортовано!" << endl;
            cout << "Масив: ";
            for (int i = 0; i < size; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
            break;

        case 4:
            cout << "Введіть число для пошуку: ";
            cin >> value;

            SortArray(arr, size);

            index = BinarySearch(arr, size, value);

            if (index != -1) {
                cout << "Елемент знайдено! Індекс: " << index << endl;
            }
            else {
                cout << "Елемент не знайдено!" << endl;
            }
            break;

        case 5:
            cout << "Введіть індекс елемента: ";
            cin >> index;

            cout << "Введіть нове значення: ";
            cin >> value;

            ReplaceElement(arr, size, index, value);
            cout << "Елемент замінено!" << endl;
            cout << "Масив: ";
            for (int i = 0; i < size; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
            break;

        case 0:
            cout << "Завершення програми..." << endl;
            break;

        default:
            cout << "Неправильний вибір!" << endl;
        }

    } while (у != 0);

    
}



