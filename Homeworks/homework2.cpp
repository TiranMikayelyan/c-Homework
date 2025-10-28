//2 chkrknvox tarri hamar
int main() {
    int n;
    std::cout << "n = ";
    std::cin >> n;

    int arr[50];
    for (int i = 0; i < n; i++) {
        std::cout << i << " element: ";
        std::cin >> arr[i];
    }

    int obshi = 0;
    for (int i = 0; i < n; i++)
        obshi ^= arr[i];

    int midbit = obshi & -obshi;    //es toxy graca vor gtnem erku chkrknvox biteri mej arajin tarber biti texy gtnenq vor dranov bajanenq erku masi

    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] & midbit)
            a ^= arr[i];  
        else
            b ^= arr[i]; 
    }
    std::cout << "Arajin chkrknvox: " << a << std::endl;
    std::cout << "Erkrord chkrknvox: " << b << std::endl;
}
