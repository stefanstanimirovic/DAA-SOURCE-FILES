void swap(int& a, int& b);

void zigzag(int n, int a[]) {
    // Indikator true oznacava da se trazi relacija "<",
    // a inace se trazi ">". Prva ocekivana relacija je "<"
    bool flag = true;

    for (int i = 0; i <= n - 2; i++) {
        if (flag) { // ocekuje se "<" 
            // Ako imamo situaciju A > B > C,
            // dobijamo A > C < B tako sto zamenimo B i C 
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
            }
        }
        else {// ocekuje se ">"
            // Ako imamo situaciju A < B < C,
            // dobijamo A < C > B tako sto zamenimo B i C
            if (a[i] < a[i + 1]) {
                swap(a[i], a[i + 1]);
            }
        }
        flag = !flag; // indikator dobija suprotnu vrednost
    }
}