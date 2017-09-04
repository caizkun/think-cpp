// summary for substring (subarray) & subsequence

substring:     a continuous segment of the string
subsequence:   a subset of the string keeping the order


// compare subsequence
bool is_subsequence(string a, string b) {
   // is string a a subsequence of string b?
   int i = 0;
   for (int j = 0; j < b.size(); ++j) {
      if (a[i] == b[j]) ++i;
   }
   return (i == a.size());
}

// compare substring
