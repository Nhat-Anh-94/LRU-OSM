#include <stdio.h>
#include <limits.h>

#define MAX_FRAME 10

int findLRU(int times[], int n) {
    int lru_index = 0;
    int min_time = INT_MAX; // Khoi tao gia tri lon nhat
    for (int i = 0; i < n; i++) {
        if (times[i] < min_time) {
            min_time = times[i];
            lru_index = i;
        }
    }
    return lru_index;
}

int main() {
    int count = 0; // Dem so loi trang
    int frames[MAX_FRAME];
    int lru = 0; // Vi tri LRU
    int times[MAX_FRAME]; // Ho tro tim kiem lru
    int flag = 0; // Vi tri duoc thay the that su
    int available = 0; // Cho biet frame co nam trong bo nho chinh hay khong

    int frame = 4; // So frame trong bo nho chinh
    int n = 20;    // So phan tu cua chuoi tham chieu
    int a[30] = {1, 0, 1, 0, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};

    printf("|Chuoi\t|");
    for (int i = 0; i < frame; i++) {
        frames[i] = -1; // Gia su ban dau cac frame trong
        times[i] = 0;
        printf("Khung %d|", i);
    }
    printf("Loi trang?\n");

    for (int i = 0; i < n; i++) {
        printf("| %d \t", a[i]);
        available = 0; // Trang khong co san

        for (int k = 0; k < frame; k++) {
            if (frames[k] == a[i]) { // Kiem tra trang co san
                available = 1; // Trang co san
                times[k] = i;  // Cap nhat thoi gian su dung
                flag = k;
            }
        }

        if (available == 0) { // Thay the trang neu khong co san
            lru = findLRU(times, frame);
            frames[lru] = a[i]; // Thay the frame tai vi tri LRU
            times[lru] = i;     // Cap nhat thoi gian su dung
            count++;            // Tang so loi trang

            // In ra man hinh
            for (int k = 0; k < frame; k++) {
                if (frames[k] >= 0)
                    printf("|%d\t", frames[k]);
                else
                    printf("|\t");
            }
            printf("| Co"); // Dau hieu nhan biet xay ra loi trang
        } else {
            for (int k = 0; k < frame; k++) {
                if (frames[k] >= 0)
                    printf("|%d\t", frames[k]);
                else
                    printf("|\t");
            }
            printf("| Khong");
        }
        printf("\n");
    }

    printf("So loi trang la: %d\n", count);
    return 0;
}
