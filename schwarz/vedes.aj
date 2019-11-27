privileged public aspect vedes{

 public LZWBinFa.Csomopont LZWBinFa.getfa() {
        return this.fa;
    }


    public void LZWBinFa.setfa(LZWBinFa.Csomopont asd) {
        this.fa=asd;
    }
    

  void around(char b) : call(public void LZWBinFa.egyBitFeldolg(char)) && args(b)
  {
    LZWBinFa test = new LZWBinFa();

        if (b == '0')
        {
          if (test.getfa().nullasGyermek() == null) 
          {
            LZWBinFa.Csomopont uj = test.new Csomopont('1');
            test.getfa().ujNullasGyermek(uj);
           test.setfa(test.gyoker);
          }
          else 
          {
            test.setfa(test.getfa().nullasGyermek());
          }
        } 
        else 
        {
          if (test.getfa().egyesGyermek() == null) 
          {
            LZWBinFa.Csomopont uj = test.new Csomopont('0');
            test.getfa().ujEgyesGyermek(uj);
           test.setfa(test.gyoker);
          }
          else
          {
              test.setfa(test.getfa().egyesGyermek());
          }
        }
    }
}
