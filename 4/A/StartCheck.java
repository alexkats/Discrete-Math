import java.io.*;
import java.util.*;
import java.math.*;

public class StartCheck {
    FastScanner in;
    PrintWriter out;

    public void solve() throws IOException {

    }

    public void run() {
        try {
            File f = new File("testing");
            BufferedReader br = new BufferedReader(new FileReader(f));
            in = new FastScanner(f);
            String[] options = new String[12];
            int q = 0;

            while (true) {
                String s = br.readLine();

                if (s == null) {
                    break;
                }

                s = s.trim();
                options[q++] = s;
            }

            String myfile = options[5] + ".a";
            f = new File(myfile);
            br = new BufferedReader(new FileReader(f));
            in = new FastScanner(f);

            String[] t = new String[5000000];
            String[] r = new String[5000000];
            int tt = 0;
            int rr = 0;

            while (true) {
                String s = br.readLine();

                if (s == null) {
                    break;
                }

                s = s.trim();
                t[tt++] = s;
            }

            myfile = options[5] + ".out";
            f = new File(myfile);
            br = new BufferedReader(new FileReader(f));
            in = new FastScanner(f);

            while (true) {
                String s = br.readLine();

                if (s == null) {
                    break;
                }

                s = s.trim();
                r[rr++] = s;
            }

            double limit = Double.parseDouble(options[11]);
            double T = 0.0;

            if (options[7].equals("Yes")) {
                T = Double.parseDouble(r[--rr]);

                out = new PrintWriter(new File("time"));
                out.println(T);
                out.close();
            }

            if (tt != rr) {
                out = new PrintWriter(new File("WA"));
            }

            double a = Double.parseDouble (t[0]);
            double b = Double.parseDouble (r[0]);

            if (a != b) {
                out = new PrintWriter(new File("WA"));
            }

            if (T > limit) {
                out = new PrintWriter(new File("TL"));
            }

            solve();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }

            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    public static void main(String[] arg) {
        new StartCheck().run();
    }
}
