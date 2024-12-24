import javax.swing.*;
import java.awt.*;
import java.awt.event.*;


class WindowPanel extends JPanel implements ActionListener ,KeyListener
{
    public static final int M_TILE   = 20;
    public static final int M_WIDTH  = M_TILE * 25;
    public static final int M_HEIGHT = M_TILE * 25;
    public static final int M_FPS    = 10;
    public static final int M_DELAY  = 1000 / M_FPS;

    private Timer m_timer = new Timer(M_DELAY, this ) ;
    private Font m_font = new Font("MS Gothic",Font.PLAIN, 100);
    private int m_iFruitX,m_iFruitY;
    private int[] m_iSnakeX, m_iSnakeY;
    private int m_iSnakeLengh = 4;
    private char m_cDir = 'r';
    private boolean m_bGameOver = false;
    @Override public void paintComponent (Graphics g)
    {
        super.paintComponent(g);
        //Grid
        g.setColor(Color.WHITE);
        for(int i = 0;i < M_WIDTH ;i += M_TILE)
            for(int j = 0;j < M_HEIGHT;j += M_TILE)
            g.drawRect(i, j, M_TILE, M_TILE);
         //Fruit
         g.setColor(Color.RED);
         g.fillRect(m_iFruitX,m_iFruitY,M_TILE,M_TILE);
         //Game over
         if(m_bGameOver){
         g.setColor(Color.RED);
         g.setFont(m_font);  
         g.drawString("Game over", M_WIDTH/2 -250, M_HEIGHT/2);
         }
        //Snake
        g.setColor(Color.GREEN);
        for(int i = 0;i < m_iSnakeLengh;i++)
        g.fillRect(m_iSnakeX[i], m_iSnakeY[i], M_TILE, M_TILE);
        g.dispose();
    }
    @Override public void actionPerformed(ActionEvent e)
    {
        if(!m_bGameOver){
        for(int i = m_iSnakeLengh ;i > 0;i--){
            m_iSnakeX[i] = m_iSnakeX[i-1];
            m_iSnakeY[i] = m_iSnakeY[i-1]; 
        }
        if(m_cDir == 'r') m_iSnakeX[0] += M_TILE;
        if(m_cDir == 'l') m_iSnakeX[0] -= M_TILE;
        if(m_cDir == 'u') m_iSnakeY[0] -= M_TILE;
        if(m_cDir == 'd') m_iSnakeY[0] += M_TILE;
        if(m_iSnakeX[0] < 0) m_iSnakeX[0] = M_WIDTH;
        if(m_iSnakeX[0] > M_WIDTH) m_iSnakeX[0] = 0;
        if(m_iSnakeY[0] < 0) m_iSnakeY[0] = M_HEIGHT;
        if(m_iSnakeY[0] > M_HEIGHT) m_iSnakeY[0] = 0;
        if(m_iSnakeX[0] == m_iFruitX && m_iSnakeY[0] == m_iFruitY){
            m_iSnakeLengh++;
            m_iFruitX = new java.util.Random().nextInt(M_WIDTH/M_TILE) * M_TILE;
        m_iFruitY = new java.util.Random().nextInt(M_WIDTH/M_TILE) * M_TILE;

        }
        for(int i = m_iSnakeLengh ;i > 0;i--){
            if(m_iSnakeX[0] == m_iSnakeX[i] && m_iSnakeY[0]
                == m_iSnakeY[i]){
                    m_bGameOver = true ;
                    m_timer.stop();
                }
        repaint();
    }
}
}
    @Override public void keyPressed(KeyEvent e)
    {
        if(e.getKeyCode() == KeyEvent.VK_RIGHT)
            if(m_cDir != 'l')
                m_cDir = 'r';
        if(e.getKeyCode() == KeyEvent.VK_LEFT)
            if(m_cDir != 'r')
                    m_cDir = 'l';
        if(e.getKeyCode() == KeyEvent.VK_UP)
            if(m_cDir != 'd')
                m_cDir = 'u';
        if(e.getKeyCode() == KeyEvent.VK_DOWN)
            if(m_cDir != 'u')
                    m_cDir = 'd';                    
    }
    @Override public void keyTyped(KeyEvent e){

    }
    @Override public void keyReleased(KeyEvent e){}
    public WindowPanel()

    {
        this.setFocusable(true);
        this.setDoubleBuffered(true);
        this.setPreferredSize(new Dimension(M_WIDTH,M_HEIGHT));
        this.setBackground(Color.BLACK);
        this.addKeyListener(this);
        m_iFruitX = new java.util.Random().nextInt(M_WIDTH/M_TILE) * M_TILE;
        m_iFruitY = new java.util.Random().nextInt(M_WIDTH/M_TILE) * M_TILE;
        m_iSnakeX = new int[200];
        m_iSnakeY = new int[200];
        m_timer.start();
    }
}

    

public class Main extends JFrame{
    public Main()
    {
        this.add(new WindowPanel());
        this.pack();
        this.setTitle("Snake game");
        this.setResizable(true);
        this.setLocationRelativeTo(null);
        this.setVisible(true);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
    public static void main(String[] args) {
        new Main();
    }
}
