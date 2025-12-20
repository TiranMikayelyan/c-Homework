int commonChild(string s1, string s2) {
    int n = (int)s1.size();          // երկու string-ների երկարությունը (նույնն են)

    vector<int> prev(n + 1, 0);      // նախորդ տողի ամենաերկար common child-ի երկարությունը
    vector<int> current(n + 1, 0);       // ընթացիկ տողի երկու string-ների ամենաերկար common child-ի երկարությունը

    for (int i = 1; i <= n; i++) {     // անցնում ենք s1-ից
        current[0] = 0;                  // սյուն 0-ն դատարկ string

        for (int j = 1; j <= n; j++) {        // անցնում ենք s2-ի տառերով


            if (s1[i - 1] == s2[j - 1]) {             // եթե s1-ի ու s2-ի տվյալ տառերը նույնն են
                current[j] = prev[j - 1] + 1;              // վերցնում ենք անկյունագիծը և ավելացնում 1

            }
            else {
               
                current[j] = max(prev[j], current[j - 1]); // եթե տառերը տարբեր են  վերցնում ենք առավելագույնը՝ վերևից կամ ձախից
                  }
        }

        prev = current;                  // ընթացիկ տողը դառնում է նախորդ
    }

    return prev[n];                 
}
