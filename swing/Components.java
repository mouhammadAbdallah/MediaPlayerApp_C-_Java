import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.net.*;
import java.io.*;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
///
/// Cette classe permet la creation d'une fenetre  contenant un textArea et trois buttons.
/// Le text area est place dans un scrollPane et les boutons se trouvent au fond de la fenetre.
///
public class Components extends JFrame {
  private static final long serialVersionUID = 1L;
  static final String DEFAULT_HOST = "localhost";
  static final int DEFAULT_PORT = 3331;
  static private Socket sock;
  static private BufferedReader input;
  static private BufferedWriter output;
  static JTextArea textArea = new JTextArea();
  JButton b1, b2, b3;
  JScrollPane s;
  JMenuBar menubar;
  JToolBar tool;
  JMenu menu;
  JTextField text = new JTextField(10);
  JLabel label = new JLabel("Write object/group Here");

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  

  ///
  /// Lit une requete depuis le Terminal, envoie cette requete au serveur,
  /// recupere sa reponse et l'affiche.
  ///
  public static void main(String argv[]) {
    new Components();
    String host = DEFAULT_HOST;
    int port = DEFAULT_PORT;
    if (argv.length >=1) host = argv[0];
    if (argv.length >=2) port = Integer.parseInt(argv[1]);
    try {
      sock = new java.net.Socket(host, port);
      textArea.append("Client connected to "+host+":"+port+"\n");
      textArea.append("Socket is ready!\n");
    }
    catch (java.net.UnknownHostException e) {
      textArea.append("Client: Couldn't find host "+host+":"+port+"\n");
    }
    catch (java.io.IOException e) {
      textArea.append("Client: Couldn't reach host "+host+":"+port+"\n");
    }

    try {
      input = new BufferedReader(new InputStreamReader(sock.getInputStream()));
      output = new BufferedWriter(new OutputStreamWriter(sock.getOutputStream()));
    }
    catch (java.io.IOException e) {
      textArea.append("Client: Couldn't open input or output streams"+"\n");
    }
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


///
/// Ce constructeur permet d'initialiser les composants graphiques de la fenetre
/// Il comporte le JMenuBar avec JMenu et le JToolBar au nord,
/// Le JTextArea dans un JScrollPane au centre et les boutons au sud.
///
    public Components() {
    JMenuBar menubar = new JMenuBar();
    JMenu menu = new JMenu("Menue");
    JToolBar tool = new JToolBar();
    JPanel panel1 = new JPanel();

    menu.add(new LeftAction("gauche"));
    menu.add(new RightAction("droite"));
    menu.add(new ExitAction("fermer"));
    menubar.add(menu);

    tool.add(new LeftAction("gauche"));
    tool.add(new RightAction("droite"));
    tool.add(new ExitAction("fermer"));

    JScrollPane scrollableTextArea = new JScrollPane(textArea);

    b1 = new JButton("montrer");
    b2 = new JButton("jouer");
    b3 = new JButton("fermer");
    b1.addActionListener(new ButtonLeft());
    b2.addActionListener(new ButtonCenter());
    b3.addActionListener(new ButtonRight());
    panel1.add(label);
    panel1.add(text);
    panel1.add(b1);
    panel1.add(b2);
    panel1.add(b3);

    add(BorderLayout.SOUTH, panel1);
    add(BorderLayout.CENTER, scrollableTextArea);
    add(BorderLayout.NORTH, tool);
    setPreferredSize(new Dimension(600,400));
    setJMenuBar(menubar);
    setTitle("Tp-Java");
    pack();
    setVisible(true);
    setDefaultCloseOperation(EXIT_ON_CLOSE);
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

///
/// Cette classe permet d'ajouter l'action au bouton qui se trouve a gauche (L'une des fonctions est d'afficher les attributs des objets).
///
public class ButtonLeft implements ActionListener{
    public void actionPerformed(ActionEvent e){
	if(text.getText().isEmpty())
	{
        textArea.append("Write object/groupe name!!\n");
	}
	else
	{
        String request, response;
        request= "Show," + text.getText()+"\n";
        textArea.append("\n" + request + "\n");
        try {
        output.write(request, 0, request.length());
        output.flush();
        textArea.append("Sent\n");
        }
        catch (java.io.IOException ex) {
        textArea.append("Client: Couldn't send message: " + ex);
        }
        try {
        response = input.readLine();
        response = response.replace(";","\n");
        textArea.append(response);
        }
        catch (java.io.IOException ex) {
        textArea.append("Client: Couldn't receive message: " + ex + "\n");
	}
    }
}
}


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


///
/// Cette classe permet d'ajouter l'action au boutton qui se trouve au centre (L'une des fonctions est de jouer les attributs des objets).
///
public class ButtonCenter implements ActionListener{
    public void actionPerformed(ActionEvent e){
        if(text.getText().isEmpty())
        {
        textArea.append("Write object/groupe name!!\n");
        }

        else
        {
        String request, response;
        request= "Play," + text.getText()+"\n";
        textArea.append("\n" + request + "\n");
        try {

        output.write(request, 0, request.length());
        output.flush();
        textArea.append("Sent\n");
        }

        catch (java.io.IOException ex) {
        textArea.append("Client: Couldn't send message: " + ex);
        }
        try {

        response = input.readLine();
        response = response.replace(";","\n");
        textArea.append(response);
        }
        catch (java.io.IOException ex) {
        textArea.append("Client: Couldn't receive message: " + ex + "\n");
        }
        }
    }
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

///
/// Cette classe permet d'ajouter l'action au bouton qui se trouve a droite (L'une des fonctions est de quitter le programe).
///
public class ButtonRight implements ActionListener{
    public void actionPerformed(ActionEvent e){
        System.exit(0);
        }
    }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

///
/// Cette classe permet d'ajouter l'action au premier button/JMenu dans Menu et ToolBar.
///
public class LeftAction extends AbstractAction {
        public LeftAction(String text) {
            super(text);
        }
        public void actionPerformed(ActionEvent e) {
            textArea.append("Button Left\n");
        }
    }


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

///
/// Cette classe permet d'ajouter l'action au deuxieme button/JMenu dans Menu et ToolBar.
///

public class RightAction extends AbstractAction {
        public RightAction(String text) {
            super(text);
        }
        public void actionPerformed(ActionEvent e) {
            textArea.append("Button Right\n");
        }
    }

/// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

////
//// Cette classe permet d'ajouter l'action au troisieme boutton/JMenu dans Menu et ToolBar.
////
public class ExitAction extends AbstractAction {
        public ExitAction(String text) {
            super(text);
        }
        public void actionPerformed(ActionEvent e) {
            System.exit(0);
        }
    }
}
