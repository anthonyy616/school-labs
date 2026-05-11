#include <stdio.h>
#include <math.h>

// Point ADT
typedef struct {
    int x, y;
} Point;

void setPoint(Point* p, int x, int y) {
    p->x = x;
    p->y = y;
}

void movePoint(Point* p, int dx, int dy) {
    p->x += dx;
    p->y += dy;
}

float distance(Point p1, Point p2) {
    int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}


int main() {
    Point p1, p2;
    int x, y, dx, dy;
    
    printf("Enter x and y for p1: ");
    scanf("%d %d", &x, &y);
    setPoint(&p1, x, y);
    printf("Enter x and y for p2: ");
    scanf("%d %d", &x, &y);
    setPoint(&p2, x, y);
    printf("Enter dx and dy to move p1: ");
    scanf("%d %d", &dx, &dy);
    movePoint(&p1, dx, dy);
    printf("Distance between p1 and p2: %.2f\n", distance(p1, p2));

    return 0;
}



//2.

#include <stdio.h>
#include <math.h>

// Date ADT
typedef struct {
    int day, month, year;
} Date;

void setDate(Date* d, int day, int month, int year) {
    d->day = day;
    d->month = month;
    d->year = year;
}

void advanceDate(Date* d) {
    d->day++;
    if (d->day > 31) {
        d->day = 1;
        d->month++;
        if (d->month > 12) {
            d->month = 1;
            d->year++;
        }
    }
}

int compareDates(Date d1, Date d2) {
    if (d1.year != d2.year) return d1.year - d2.year;
    if (d1.month != d2.month) return d1.month - d2.month;
    return d1.day - d2.day;
}

int main() {

    Date d1, d2;
    int day, month, year;
    printf("\nEnter day, month, year for d1: ");
    scanf("%d %d %d", &day, &month, &year);
    setDate(&d1, day, month, year);
    printf("Enter day, month, year for d2: ");
    scanf("%d %d %d", &day, &month, &year);
    setDate(&d2, day, month, year);
    advanceDate(&d1);
    int cmp = compareDates(d1, d2);
    printf("d1 after advance: %d/%d/%d\n", d1.day, d1.month, d1.year);
    printf("Comparison (d1 - d2): %d\n", cmp);

    return 0;
}

//If we get lower d1 than d2 in compareDates, we multiply the negative difference by -1 to make it positive

int compareDates(Date d1, Date d2) {
    int cmp;
    if (d1.year != d2.year) cmp = d1.year - d2.year;
    else if (d1.month != d2.month) cmp = d1.month - d2.month;
    else cmp = d1.day - d2.day;

    if (cmp < 0) cmp *= -1; // Multiply negative difference by -1 to make it positive
    return cmp;
}