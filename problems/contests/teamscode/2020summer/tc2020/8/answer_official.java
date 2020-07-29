import java.util.*;
public class europeEscapade {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int N = Integer.parseInt(s.nextLine());
        StringTokenizer st = new StringTokenizer(s.nextLine());
        int[] lengths = new int[N+1];
        for (int i = 0; i < N+1; i++)
            lengths[i] = Integer.parseInt(st.nextToken());
        ArrayList<ArrayList<Character>> countries = new
            ArrayList<ArrayList<Character>>();
        for (int i = 0; i < N+1; i++) {
            ArrayList<Character> thisCountry = new
                ArrayList<Character>();
            countries.add(thisCountry);
            st = new StringTokenizer(s.nextLine());
            while (st.hasMoreTokens()) {
                countries.get(i).add(st.nextToken().charAt(0));
            }
        }
        int count = 0;
        for (int i = 1; i < N+1; i++) {
            int offset = -(lengths[i]-1);
            int maxCountries = 0;
            while (offset < lengths[0] -1) {
                int indYou = Math.max(0, offset);
                int indThem = Math.max(0, -offset);
                int curCountries = 0;
                while (indYou < lengths[0] && indThem < lengths[i]) {
                    if (countries.get(0).get(indYou) ==
                            countries.get(i).get(indThem))
                        curCountries++;
                    indYou++;
                    indThem++;
                }
                if (curCountries > maxCountries) maxCountries =
                    curCountries;
                offset += 1;
            }
            count += maxCountries;
        }
        System.out.println(count);
    }
}

