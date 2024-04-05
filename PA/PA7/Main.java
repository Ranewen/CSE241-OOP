import java.util.ArrayList;
import java.util.List;

// Interface for visual objects
interface Visual 
{
    void show();
    String getName();
    void info();
}

// Interface for playable objects
interface Playable 
{
    void play();
    String getName();
    void info();
}

// Interface for non-visual objects
interface NonVisual 
{
    void info();
}

// Interface for non-playable objects
interface NonPlayable 
{
    void info();
}

// Base class for all objects in the dataset
class DatasetObject 
{
    private String name;
    private String otherInfo;

    public DatasetObject(String name, String otherInfo) 
    {
        this.name = name;
        this.otherInfo = otherInfo;
    }

    public String getName() 
    {
        return name;
    }

    public String getOtherInfo() 
    {
        return otherInfo;
    }

    // This method prints the basic information of the object
    public void info() 
    {
        System.out.println("Name: " + name);
        System.out.println("Other info: " + otherInfo);
    }
}

// Image class (non-playable, visual)
class Image extends DatasetObject implements NonPlayable, Visual 
{
    private String dimensionInfo;

    public Image(String name, String dimensionInfo, String otherInfo) 
    {
        super(name, otherInfo);
        this.dimensionInfo = dimensionInfo;
    }

    public String getDimensionInfo() 
    { 
        return dimensionInfo; 
    } 

    @Override 
    public void show() 
    { 
        System.out.println("Showing image: " + getName()); 
    } 

    // This method overrides the info method of the superclass and adds more information 
    @Override 
    public void info() 
    { 
        super.info(); 
        System.out.println("Dimension info: " + dimensionInfo); 
    } 
}

// Audio class (playable, non-visual)
class Audio extends DatasetObject implements Playable, NonVisual 
{
    private String duration; 

    public Audio(String name, String duration, String otherInfo) 
    {

        super(name, otherInfo); 
        this.duration = duration; 
    } 

    public String getDuration() 
    { 
        return duration; 
    } 

    @Override 
    public void play() 
    { 
        System.out.println("Playing audio: " + getName()); 
    } 
}

// Video class (playable, visual)
class Video extends DatasetObject implements Playable, Visual 
{
    private String duration; 

    public Video(String name, String duration, String otherInfo) 
    { 
        super(name, otherInfo); 
        this.duration = duration; 
    } 

   public String getDuration() 
    { 
        return duration; 
    } 

    @Override 
    public void show() 
    { 
        System.out.println("Showing video: " + getName()); 
    } 

    @Override 
    public void play() 
    { 
        System.out.println("Playing video: " + getName()); 
    } 
}

// Text class (non-playable, non-visual)
class Text extends DatasetObject implements NonPlayable, NonVisual 
{
    public Text(String name, String otherInfo) 
    { 
        super(name, otherInfo); 
    } 
}

// Dataset class
class Dataset 
{
    private List<DatasetObject> objects; 
    private List<Player> players; 
    private List<Viewer> viewers; 

    public Dataset() 
    { 
        objects = new ArrayList<>(); 
        players = new ArrayList<>(); 
        viewers = new ArrayList<>(); 
    } 

    public void register(Player player) 
    { 
        players.add(player); 
    } 

    public void register(Viewer viewer) 
    {  
        viewers.add(viewer);  
    }  

    public void add(DatasetObject object) 
    {  
        objects.add(object);  
        notifyObservers(object);  
    }  

    // cast the object to DatasetObject before removing it  
    public void remove(DatasetObject object) 
    {  
        objects.remove((DatasetObject) object);  
        notifyObservers(object);  
    }  

    private void notifyObservers(DatasetObject object) 
    {  
        for (Player player : players) 
        {  
            if (object instanceof Playable) 
            {  
                player.update((Playable) object);  
            }  
        }  

        for (Viewer viewer : viewers) 
        {  
            if (object instanceof Visual && !(object instanceof Playable)) 
            {  
                viewer.update((Visual) object);  
            }  
        }  
    }  
}

// Player class
class Player
{
    private List<Playable> playlist; 
    private int currentIndex; 

    public Player() 
    { 
        playlist = new ArrayList<>(); 
        currentIndex = -1; 
    } 

    public void update(Playable object) 
    { 
        playlist.add(object); 
        if (currentIndex == -1) 
        { 
           currentIndex = 0; 
        } 
    } 

    public void remove(Playable object) 
    { 
        playlist.remove(object); 
        if (currentIndex >= playlist.size()) 
        { 
            currentIndex = playlist.size() - 1; 
        } 
    }     

    public void playNext() 
    { 
       if (currentIndex < playlist.size() - 1) 
        {
            currentIndex++;
            playlist.get(currentIndex).play();
        } 
        else 
        { 
            System.out.println("No more items in the playlist."); 
        } 
    } 

    public void playPrevious() 
    { 
        if (currentIndex > 0) 
        {
            currentIndex--;
            playlist.get(currentIndex).play();
        } 
        else 
        { 
            System.out.println("Already at the first item in the playlist."); 
        } 
    } 

    public void showPlaylist() 
    { 
        System.out.println("Current playlist:"); 
        for (int i = 0; i < playlist.size(); i++) 
        { 
            Playable object = playlist.get(i); 
            System.out.println((i + 1) + ". " + object.getName() + " (" + object.getClass().getSimpleName() + ")"); 
        } 
    } 

    public Playable currently_playing() 
    {     
        if (currentIndex != -1) 
        {
            return playlist.get(currentIndex);
        } 
        else 
        { 
           return null; 
        } 
    } 
}

// Viewer class
class Viewer 
{
    private List<Visual> viewlist;
    private int currentIndex;

    public Viewer() 
    {
        viewlist = new ArrayList<>();
        currentIndex = -1;
    }

    public void update(Visual object) 
    {
        viewlist.add(object);
        if (currentIndex == -1) 
        {
            currentIndex = 0;
        }
    }

    public void remove(Visual object) 
    {
        viewlist.remove(object);
        if (currentIndex >= viewlist.size()) 
        {
            currentIndex = viewlist.size() - 1;
        }
    }

    public void showNext() 
    {
        if (currentIndex < viewlist.size() - 1) 
        {
            currentIndex++;
            viewlist.get(currentIndex).show();
        } 
        else 
        {
            System.out.println("No more items in the viewlist.");
        }
    }

    public void showPrevious() 
    {
        if (currentIndex > 0) {
            currentIndex--;
            viewlist.get(currentIndex).show();
        } 
        else 
        {
            System.out.println("Already at the first item in the viewlist.");
        }
    }

    public void showViewlist() 
    {
        System.out.println("Current viewlist:");
        for (int i = 0; i < viewlist.size(); i++) 
        {
            Visual object = viewlist.get(i);
            System.out.println((i + 1) + ". " + object.getName() + " (" + object.getClass().getSimpleName() + ")");
        }
    }

    public Visual currently_viewing() 
    {
        if (currentIndex != -1) 
        {
            return viewlist.get(currentIndex);
        } 
        else 
        {
            return null;
        }
    }
}

public class Main 
{

    public static void main(String[] args) 
    {
        //This is our dataset. We have only one dataset. 
        Dataset ds = new Dataset();

        //Lets create different observers. 
        Player p1 = new Player();
        Player p2 = new Player();
        Viewer v1 = new Viewer();
        Viewer v2 = new Viewer();

        //Lets register them to our dataset so that they can reach to data and updates. 
        //You can also register them to the dataset when you create them. 
        // ds has to figure out the type of the observer. 
        // it should not send unrelated information. 
        // For example, viewer objects don't want to know anything about playable objects. 
        ds.register(p1);
        ds.register(p2);
        ds.register(v1);
        ds.register(v2);

        //Dataset should also support un-registering. 
        //ds.remove_observer(p1); 
        //p1 no longer receives any update or list of items. 

        //Here we create different objects. 
        ds.add(new Image("imagename1", "dimension info1", "other info1"));
        ds.add(new Image("imagename2", "dimension info2", "other info2"));
        ds.add(new Image("imagename3", "dimension info3", "other info3"));
        ds.add(new Image("imagename4", "dimension info4", "other info4"));
        ds.add(new Image("imagename5", "dimension info5", "other info5"));

        ds.add(new Audio("audioname1", "duration1", "other info1"));
        ds.add(new Audio("audioname2", "duration2", "other info2"));
        ds.add(new Audio("audioname3", "duration3", "other info3"));

        ds.add(new Video("videoname1", "duration1", "other info1"));
        ds.add(new Video("videoname2", "duration2", "other info2"));
        ds.add(new Video("videoname3", "duration3", "other info3"));

        ds.add(new Text("textname1", "other info1"));
        ds.add(new Text("textname2", "other info2"));
        ds.add(new Text("textname3", "other info3"));

        //Lets use one of the player objects.  
        
        //We can get the currently playing object  
        Playable po = p1.currently_playing();

        //This prints info about the playing object.  
        po.info();

        //we can remove this object from the dataset  
        ds.remove((DatasetObject) po); // cast to DatasetObject before removing

        //po is no longer in the dataset. all of the interested observers will get this update.  

        //similarly, viewer object:  
        Visual np = v1.currently_viewing();

        //This prints info about the viewing object.  
        np.info();

        //we can remove this object from the dataset  
        ds.remove((DatasetObject) np); // cast to DatasetObject before removing

        //np is no longer in the dataset. all of the interested observers will get this update.  

        //we can also use the player and viewer methods to play or show the next or previous items in their lists  
        p1.playNext();
        p1.playPrevious();
        v2.showNext();
        v2.showPrevious();

        //we can also show the current playlist or viewlist of each observer  
        p1.showPlaylist();
        p2.showPlaylist();
        v1.showViewlist();
        v2.showViewlist();
    }
}
