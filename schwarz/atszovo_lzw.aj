public aspect atszovo_lzw {

    public pointcut fgvHívás(): call(public double LZWBinFa.getAtlag());

   before():fgvHívás(){
        System.out.println("getAtlag meghívása előtt ez a szöveg megjelenik");
    }
}