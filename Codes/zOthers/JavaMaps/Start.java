import java.util.*;

public class Start{
  public static void main(String[] Args) {
    Map<String, Map<String, Map<Integer, Integer> > > icc = createTwoStatsPlayersForTeams();
    for(String team: icc.keySet()) {
      System.out.println("{\n"+team + " = "+icc.get(team) + "\n}\n");
    }

  }

  private static Map<Integer, Integer> createFourRandomRunForYearMapForPlayer() {
    Map<Integer, Integer> runForYear = new HashMap<>();

    int year = 2014;
    int run = 0;

    Random r = new Random();
    int low = 10;
    int high = 100;


    for(int i=0; i < 4; i++) {
      run = r.nextInt(high-low) + low;
      // run = (int) Math.random();
      runForYear.put(year, run);
      year++;
    }
    return runForYear;
  }

  private static Map<String, Map<Integer, Integer> > createFiveRandomStatsForPlayersTeam1() {
    Map<String, Map<Integer, Integer> > statsForPlayers = new TreeMap<>();
    
    statsForPlayers.put("Sakib", createFourRandomRunForYearMapForPlayer());
    statsForPlayers.put("Tamim", createFourRandomRunForYearMapForPlayer());
    statsForPlayers.put("Taskin", createFourRandomRunForYearMapForPlayer());
    statsForPlayers.put("Mashrafi", createFourRandomRunForYearMapForPlayer());
    statsForPlayers.put("Mahmudullah", createFourRandomRunForYearMapForPlayer());
    
    return statsForPlayers;
  }

  private static Map<String, Map<Integer, Integer> > createFiveRandomStatsForPlayersTeam2() {
    Map<String, Map<Integer, Integer> > statsForPlayers = new TreeMap<>();
    
    statsForPlayers.put("Liton", createFourRandomRunForYearMapForPlayer());
    statsForPlayers.put("Mosaddek", createFourRandomRunForYearMapForPlayer());
    statsForPlayers.put("Rubel", createFourRandomRunForYearMapForPlayer());
    statsForPlayers.put("Hasan", createFourRandomRunForYearMapForPlayer());
    statsForPlayers.put("Sabbir", createFourRandomRunForYearMapForPlayer());
    
    return statsForPlayers;
  }

  private static Map<String, Map<String, Map<Integer, Integer> > > createTwoStatsPlayersForTeams() {
    Map<String, Map<String, Map<Integer, Integer> > > statsPlayersForTeams = new TreeMap<>();
    
    statsPlayersForTeams.put("team 1", createFiveRandomStatsForPlayersTeam1());   
    statsPlayersForTeams.put("team 2", createFiveRandomStatsForPlayersTeam2());

    return statsPlayersForTeams;
  }
}