public class Lzw {

public static void usage() {
  System.out.println("Usage: Lzw in_file -o out_file");
}

public static void main(String args[]) {

  if (args.length != 3) {
    usage();
    System.exit(-1);
  }

  String inFile = args[0];
  if (!"-o".equals(args[1])) {
    usage();
    System.exit(-1);
  }

  try {
    java.io.FileInputStream beFile = new java.io.FileInputStream(new java.io.File(args[0]));
    java.io.PrintWriter kiFile = new java.io.PrintWriter( new java.io.BufferedWriter( new java.io.FileWriter(args[2])));
    byte[] b = new byte[1];

    LZWBinFa binFa = new LZWBinFa();

    while (beFile.read(b) != -1) {
      if (b[0] == 0x0a) {
        break;
      }
    }

    boolean kommentben = false;
    while (beFile.read(b) != -1) {

      if (b[0] == 0x3e) {
        kommentben = true;
        continue;
      }

      if (b[0] == 0x0a) {
        kommentben = false;
        continue;
      }

      if (kommentben) {
        continue;
      }

      if (b[0] == 0x4e) {
        continue;
      }

      for (int i = 0; i < 8; ++i) {

        if ((b[0] & 0x80) != 0) {
          binFa.egyBitFeldolg('1');
        } else {
          binFa.egyBitFeldolg('0');
        }
        b[0] <<= 1;

      }

    }

    binFa.kiir(kiFile);
    kiFile.println("depth = " + binFa.getMelyseg());
    kiFile.println("mean = " + binFa.getAtlag());
    kiFile.println("var = " + binFa.getSzoras());
    kiFile.close();
    beFile.close();
  } catch (java.io.FileNotFoundException fnfException) {
    fnfException.printStackTrace();
  } catch (java.io.IOException ioException) {
    ioException.printStackTrace();
  }
}
}
