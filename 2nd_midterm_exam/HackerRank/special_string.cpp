long substrCount(int n, string s) {                 //block-ը էտ մի քանի կրկնվող տառերն են իրար հետևից
    n = (int)s.size();                                // n-ը հավասարեցնում ենք իրական երկարությանը
    if (n == 0) return 0;                             

    long qanak = 0;                                     

    vector<int> len;                                  // block-ների երկարությունները պահելու համար
    vector<char> ch;                                  // տառերը պահելու համար
    len.reserve(n);                                   // նախապես տեղ ենք պահում 
    ch.reserve(n);                                    

    for (int i = 0; i < n; ) {                        
        char c = s[i];                                 // պահում ենք տվյալ block-ի տառը
        int j = i;                                     

        while (j < n && s[j] == c) j++;                // հաշվում ենք քանի հատ նույն տառից կա 

        ch.push_back(c);                               // պահում ենք block-ի տառը
        len.push_back(j - i);                          // պահում ենք block-ի երկարությունը
        
        i = j;                                         // անցնում ենք հաջորդ block-ի սկիզբը
    }

    int m = (int)len.size();                           // քանի block ունենք ընդհանուր

    for (int i = 0; i < m; i++) {                      
        long L = len[i];                               // տվյալ block-ի երկարությունը
        qanak += L * (L + 1) / 2;                        //  նույն տառերից substring-ների քանակը
    }

    for (int i = 1; i < m - 1; i++) {                  // միջին block-ներից սկսած
        if (len[i] == 1 && ch[i - 1] == ch[i + 1]) {   // cպայման՝ միջինը 1 հատ է, ու կողքերը նույն տառն են, դրա համար
            qanak += (len[i - 1] < len[i + 1])           // ավելացնում ենք՝
                   ? len[i - 1]                         // ձախ ու աջ block-ների փոքրագույն երկարությունը
                   : len[i + 1];                   
        }
    }

    return qanak;                                        
}
