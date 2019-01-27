#pragma once



class ChessWZQ extends JFrame
{
	JPanel contentPane;
	BorderLayout borderLayout1 = new BorderLayout();

	protected Image white = null;
	protected Image black = null;
	protected static int pColor; // �˵���ɫ
	protected static int cColor; //���Ե���ɫ

	static bool ptocFlag = false;
	bool pFirst = false;
	private int bestX = 0; // �����ҵ���õ�����λ�õ� X����
	private int bestY = 0; // �����ҵ���õ�����λ�õ�Y����
	private int RectX1 = 0; // �������� (x,y)ȷ�����η�Χ
	private int RectY1 = 0; // ����Ϊ 9
	private int RectX2 = 0; // ��СΪ 9*9
	private int RectY2 = 0;
	private int weightBoard[][];

	static Socket socket;
	private static int PORT;
	static ObjectInputStream in;
	static ObjectOutputStream out;
	string name = null;
	string serverAddress = null;
	static char send[];
	public static Message message = new Message();
	public static bool beginFlag = false;

	BoardPanel bpanel = new BoardPanel();
	JPanel jpanel3 = new JPanel();
	JLabel label1 = new JLabel("Player1");
	JLabel label2 = new JLabel(" VS ");
	JLabel label3 = new JLabel("Player2");
	JLabel label4 = new JLabel("Player List ");
	JLabel label5 = new JLabel("Message list... ");
	static JLabel label6 = new JLabel("welcome");
	JLabel label7 = new JLabel("Host");
	JLabel label8 = new JLabel("Player");
	JRadioButton jrbBlack = new JRadioButton("Black");
	JRadioButton jrbWhite = new JRadioButton("White");
	DefaultListModel lItems = new DefaultListModel();
	JList list = new JList(lItems);
	JMenuBar mb = new JMenuBar();
	JMenu create = new JMenu("Create");
	JMenu setting = new JMenu("Setting");
	JMenu quit = new JMenu("Quit");
	JMenu about = new JMenu("About");
	JMenuItem cPtoP = new JMenuItem("Play With people");
	JMenuItem cPtoC = new JMenuItem("Play With Computer");
	JMenuItem load = new JMenuItem("Load game...");
	JMenuItem save = new JMenuItem("Save ...");
	//    JMenuItem sLimited = new JMenuItem("��ֹ����");
	//    JMenuItem sNoLimited = new JMenuItem("�������");


	public ChessWZQ()
	{
		enableEvents(AWTEvent.WINDOW_EVENT_MASK);
		getContentPane().setLayout(null);
		weightBoard = new int[15][15]; // ����ÿ��λ�õ���Ҫ��

		PORT = Server.PORT;//�����׽��ֶ˿�
		send = new char[60];

		try {
			jbInit();
		}
		catch (Exception e)
		{
			e.printStackTrace();
		}

		try {
			getContentPane().setLayout(null);

			jrbBlack.addActionListener(new ActionListener()
			{
				public void actionPerformed(ActionEvent e)
				{
					bpanel.setColor(1);
					cColor = 2;
					jrbBlack.setEnabled(false);
					jrbWhite.setEnabled(false);
					drawChess(1);
					jrbWhite.setSelected(true);
					if (ptocFlag == true)
					{
						return;
					}
					Message ms = new Message();
					ms.color = 1;
					ms.type = 13;
					try{
						out.writeObject(ms);
					}
					catch (IOException error)
					{
						error.printStackTrace();
					}
				}
			});
			jrbWhite.addActionListener(new ActionListener()
			{
				public void actionPerformed(ActionEvent e)
				{
					bpanel.setColor(2);
					cColor = 1;
					jrbWhite.setEnabled(false);
					jrbBlack.setEnabled(false);
					drawChess(2);
					jrbBlack.setSelected(false);
					if (ptocFlag == true)
					{
						return;
					}
					Message ms = new Message();
					ms.color = 2;
					ms.type = 13;
					try{
						out.writeObject(ms);
					}
					catch (IOException error)
					{
						error.printStackTrace();
					}
				}
			});
			about.addMouseListener(new MouseAdapter()
			{
				public void mouseClicked(MouseEvent e)
				{
					JOptionPane.showMessageDialog(null,
						"Author: Kahn \nCopyright (c) 2007-CUIT \nMail:zhao4824593@163.com",
						"������1.0(beta)", JOptionPane.INFORMATION_MESSAGE);
				}
			});
			quit.addMouseListener(new MouseAdapter()
			{
				public void mouseClicked(MouseEvent e)
				{
					int flag = JOptionPane.showConfirmDialog(null,
						"Quit the Program ?",
						"Are you sure to quit ?",
						JOptionPane.YES_NO_OPTION, JOptionPane.QUESTION_MESSAGE);
					if (flag == 0)
					{   //ȷ��
						// �Ͽ��ͷ���˵�����
						sendDisconnect();
						System.exit(0);
					}
				}
			});
			setting.addMouseListener(new MouseAdapter()
			{
				public void mouseClicked(MouseEvent e)
				{

					Object selection[] = { "Forbiden", "Allow any" };
					Object set = JOptionPane.showInputDialog(null,
						"Setting...", "would you allow any method?",
						JOptionPane.QUESTION_MESSAGE, null, selection, selection[0]);
					if (ptocFlag == true)
					{
						return;
					}
					Message ms = new Message();
					if (set == null)
					{
						return;
					}
					if (set.toString().equals(selection[0]))
					{
						ms.setting = false;
					}
					else{
						ms.setting = true;
					}
					//System.out.println("setting begin..."+msg.setting);
					ms.type = 12;
					try{
						out.writeObject(ms);
					}
					catch (IOException error)
					{
						error.printStackTrace();
					}
				}
			});
			cPtoP.addActionListener(new ActionListener()
			{
				public void actionPerformed(ActionEvent e)
				{
					ptocFlag = false;
					JOptionPane.showMessageDialog(null,
						"You can choose a player from the listBox on the right", "Welcome...",
						JOptionPane.INFORMATION_MESSAGE);
				}
			});
			cPtoC.addActionListener(new ActionListener()
			{
				public void actionPerformed(ActionEvent e)
				{
					if (ptocFlag == true)
					{
						int flag = JOptionPane.showConfirmDialog(null,
							"You give up... ?", "Message",
							JOptionPane.YES_NO_OPTION, JOptionPane.QUESTION_MESSAGE);
						if (flag == 0)
						{
							newGame();
							return;
						}
					}
					label3.setText("Computer");
					Object selection[] = { "Computer First", "You First" };
					Object set = JOptionPane.showInputDialog(null,
						"choose who first...", "setting...",
						JOptionPane.QUESTION_MESSAGE, null,
						selection, selection[0]);
					ptocFlag = true;
					if (set.toString().equals(selection[1]))
					{
						pFirst = true;
					}
					else
					{
						pFirst = false;
					}
					pColor = bpanel.getColor();
					if (pColor == 1)
					{
						jrbBlack.setSelected(true);
						jrbWhite.setSelected(false);
						cColor = 2;
					}
					else
					{
						jrbWhite.setSelected(true);
						jrbBlack.setSelected(false);
						cColor = 1;
					}
					jrbBlack.setEnabled(false);
					jrbWhite.setEnabled(false);
					ptoComputer();
				}
			});

			create.setBounds(5, 5, 40, 20);
			setting.setBounds(45, 5, 40, 20);
			quit.setBounds(85, 5, 40, 20);
			about.setBounds(125, 5, 40, 20);
			create.add(cPtoP);
			create.add(cPtoC);
			//create.add(load);
			//create.add(save);
			mb.add(create);
			mb.add(setting);
			mb.add(quit);
			mb.add(about);
			this.setJMenuBar(mb);

			bpanel.setBounds(0, 0, 470, 460);
			bpanel.setBorder(BorderFactory.createMatteBorder(0, 0, 1, 1, Color.ORANGE));

			jpanel3.setLayout(null);
			jpanel3.setBorder(BorderFactory.createMatteBorder(1, 1, 1, 1, Color.DARK_GRAY));
			jpanel3.setBounds(470, 0, 180, 460);
			label7.setBounds(10, 10, 30, 20);
			label7.setBackground(Color.blue);
			label7.setForeground(Color.yellow);
			label8.setBounds(90, 10, 40, 30);
			label8.setBackground(Color.blue);
			label8.setForeground(Color.yellow);
			label1.setBounds(10, 40, 50, 20);
			label2.setForeground(Color.RED);
			label2.setBounds(60, 40, 50, 20);
			label3.setBounds(90, 40, 70, 20);
			label4.setForeground(Color.BLUE);
			label4.setBounds(10, 78, 70, 20);
			label5.setBackground(Color.magenta);
			label5.setForeground(Color.RED);
			label5.setBounds(15, 395, 160, 20);
			label6.setBounds(15, 415, 180, 20);
			//label6.setBorder(BorderFactory.createMatteBorder(1,1,1,1,Color.yellow));

			jrbBlack.setSelected(true);
			jrbBlack.setBounds(10, 380, 80, 15);
			jrbWhite.setBounds(90, 380, 80, 15);

			list.setBorder(BorderFactory.createMatteBorder(1, 1, 1, 1, Color.black));
			list.setBounds(10, 100, 150, 265);

			list.addMouseListener(new MouseAdapter()
			{
				public void mouseClicked(MouseEvent e)
				{
					// ˫��ѡ�����
					if (e.getClickCount() == 2)
					{
						String str = list.getSelectedValue().toString();
						if (str.equals(name) == true)
						{
							label6.setText("You can't choose yourself");
							return;
						}
						label3.setText(str);
						list.setEnabled(false);

						Message ms = new Message();
						ms.type = 3;  //����ͱ�����Ϸ
						strToCharArray(str, ms.msg);
						ms.color = bpanel.getColor();
						//System.out.println("request for play with "+str);
						try{
							out.writeObject(ms);
						}
						catch (IOException er)
						{
							er.printStackTrace();
						}
					}
				}
			});
			jpanel3.add(label1);
			jpanel3.add(label2);
			jpanel3.add(label3);
			jpanel3.add(label4);
			jpanel3.add(label5);
			jpanel3.add(label6);
			jpanel3.add(label7);
			//            jpanel3.add(label8);
			jpanel3.add(jrbBlack);
			jpanel3.add(jrbWhite);
			jpanel3.add(list);

			// getContentPane().add(jpanel1);
			getContentPane().add(bpanel);
			getContentPane().add(jpanel3);

			// lItems.add(0,"Kahn1");
			// lItems.add(0,"Kahn2");

		}
		catch (Exception e)
		{
			e.printStackTrace();
		}

	}

	//�����ʼ��
	private void jbInit() throws Exception
	{
		contentPane = (JPanel) this.getContentPane();
		contentPane.setLayout(borderLayout1);
		this.setSize(new Dimension(660, 530));
		this.setTitle("������ͻ���(beta)");
	}
	/**
	*���ͶϿ����󵽷����
	* type = 7
	*/
	public void sendDisconnect()
	{
		Message ms = new Message();
		ms.type = 7;
		try{
			out.writeObject(ms);
		}
		catch (IOException e)
		{
			e.printStackTrace();
		}
	}
	public void drawChess(int col)
	{
		Graphics g = jpanel3.getGraphics();
		if (col == 1) g.setColor(Color.black);
		else g.setColor(Color.white);
		g.fillOval(50, 10, 20, 20);
	}

	/**
	* ��ʽ�� java ChessWZQ < server address> <player name>
	*   args[0]=����˵�ַ args[1]=�������
	*/
	public static void main(String[] args)
	{
		ChessWZQ wzq = new ChessWZQ();
		wzq.setResizable(false);
		wzq.setVisible(true);
		wzq.drawChess(1);   //Ĭ����ɫΪ��ɫ

		Message ms = new Message();
		if (args[0] != null)
			wzq.serverAddress = new String(args[0]);
		else
			wzq.serverAddress = new String("localhost");
		if (args[1] != null)
			wzq.name = new String(args[1]);
		else
			wzq.name = new String("Kahn");
		wzq.strToCharArray(wzq.name, ms.msg);
		try{
			// �������еõ����������
			InetAddress addr = InetAddress.getByName(wzq.serverAddress);
			//System.out.println("address "+ addr.toString()+" port: "+PORT);
			socket = new Socket(addr, PORT);
			//System.out.println("set socket successful...");

			out = new ObjectOutputStream(
				socket.getOutputStream());
			in = new ObjectInputStream(
				socket.getInputStream());

			ms.type = 1;
			try{
				out.writeObject(ms);
			}
			catch (IOException e)
			{
				e.printStackTrace();
			}
			while (true)
			{
				try {
					ms = (Message)in.readObject();
					//System.out.println("get message from server...type = "+ms.type);
					wzq.doMessage(ms);
				}
				catch (ClassNotFoundException e)
				{
					e.printStackTrace();
				}
			}
			//System.out.println("ms.coordinateX + , + msg.coordinateY");
			//System.out.println(ms.color);
			//System.out.println("close ...");
			//socket.close();
		}
		catch (IOException e)
		{
			e.printStackTrace();
		}

	}
	/**
	* ����ӷ���˷�������Ϣ
	*  msg
	*/
	protected int doMessage(Message msg)
	{
		String str = arrayToString(msg.msg);
		//System.out.println("msg name = "+str+" msg.type = "+msg.type);
		switch (msg.type)
		{
		case 2:{//��Ӧ������
				   putChessman(msg);
				   break;
		}
		case 3:{//������ҵ�����
				   requestAnother(msg);
				   break;
		}
		case 4:{ // B�ܾ���A��Ϸ
				   getDeny(msg);
				   break; }
		case 5:{ // B ����A������
				   acceptToPlay(msg);
				   break; }
		case 6:{
				   getVictory(msg);
				   break; }
		case 7:{
				   getDisconnection(msg);
				   break; }
		case 9:{//�ظ��������ҵ����еĿͻ���
				   ///System.out.println("add new player to list type = 9 name = "+str+"msg[0]= "+msg.msg[0]);
				   lItems.add(0, str);
				   break;
		}
		case 10:{ //���ӻظ�
					//System.out.println("add him self  type = 10 name = "+str+"msg[0]= "+msg.coordinateX+msg.msg[0]);
					label1.setText(str);
					label6.setText("welcome " + str);
					lItems.add(0, str);
					break;
		}
		case 14:{ //B���պ�A��Ϸ,����MSG��������Ϸѡ��

					break;
		}
		case 15:{
					lItems.clear();
					break;
		}
		case 17:{
					getFailed(msg);
					break;
		}
		case 20:{
					ptocWin(msg);
					break;
		}
		}
		return 0; //����
	}
	private void ptocWin(Message ms)
	{
		String str = this.arrayToString(ms.msg);
		JOptionPane.showMessageDialog(null, str + " win the game!", "Win the game", JOptionPane.INFORMATION_MESSAGE);
		newGame();
	}
	/**
	* ��Ϸʧ�ܲ���ʼ�µ���Ϸ
	* type == 17
	* msg
	*/
	public void getFailed(Message msg)
	{
		bpanel.drawChess(msg.coordinateX, msg.coordinateY);
		JOptionPane.showMessageDialog(null,
			"Sorry,You've failed the game",
			"Try Again",
			JOptionPane.INFORMATION_MESSAGE);
		label3.setText("Player2");
		// ��������Ϸ
		newGame();
	}
	/**
	*��һ����ҷ��ͶϿ�����
	* type ==7
	* msg
	*/
	public void getDisconnection(Message msg)
	{
		getVictory(msg);
	}
	/**
	* ��Ϸʤ��
	* type ==6
	* msg
	*/
	public void getVictory(Message msg)
	{
		JOptionPane.showMessageDialog(null,
			"You  Win  The  Game",
			"Congratulations",
			JOptionPane.INFORMATION_MESSAGE);
		//��������Ϸ
		label3.setText("Player2");
		newGame();
	}
	/**
	* ���˻�ʤʱ ,���ܹ���ʼ����Ϸ
	* msg
	*/
	public void newGame()
	{
		jrbBlack.setEnabled(true);
		jrbWhite.setEnabled(true);
		jrbBlack.setSelected(true);
		jrbWhite.setSelected(false);
		list.setEnabled(true);
		setting.setEnabled(true);
		bpanel.clearBoard();
		drawChess(1);
		pColor = 1; cColor = 2;
		if (ptocFlag == false)
		{
			Message msg = new Message();
			msg.type = 19;
			strToCharArray(name, msg.msg);
			try {
				out.writeObject(msg);
			}
			catch (IOException e)
			{
				e.printStackTrace();
			}
		}
		ptocFlag = false;
		beginFlag = false;
	}

	public void putChessman(Message msg)
	{
		if (ptocFlag == false)
		{
			bpanel.updateBoard(msg.coordinateX, msg.coordinateY);
			bpanel.drawChess(msg.coordinateX, msg.coordinateY);
			beginFlag = true;
			return;
		}
		else{
			//���±������
			// �����������겢����
		}
	}
	/**
	*  A��B�յ�ȷ����Ϣ������B������
	* type= 5  B ���ܺ�A��Ϸ
	*  msg = B������
	*/
	public void acceptToPlay(Message msg)
	{
		String str = arrayToString(msg.msg);
		String ss = null;
		if (msg.color == 1)
		{
			ss = new String("white");
			bpanel.setColor(2);
		}
		else{
			ss = new String("black");
			bpanel.setColor(1);
		}
		JOptionPane.showMessageDialog(null,
			"OK. " + str + " have accepted your requestion\nYour color is" + ss,
			"Game will to begin...", JOptionPane.ERROR_MESSAGE);

		list.setEnabled(false);
		jrbBlack.setEnabled(false);
		jrbWhite.setEnabled(false);
		setting.setEnabled(false);
		beginFlag = true;
	}
	/**
	*  A�յ�B�ľܾ���Ϣ
	* type ==4   �ܾ���Ϸ
	* msg
	*/
	public void getDeny(Message msg)
	{
		String str = arrayToString(msg.msg);
		JOptionPane.showMessageDialog(null,
			"I'm sorry\n" + str + " denied your requestion",
			"Sorry...", JOptionPane.ERROR_MESSAGE);
		list.setEnabled(true);
		label3.setText("Player2");
	}
	/**
	* A�����B��Ϸ��B�Ķ�������
	* msg = �����ߵ�����
	*/
	public void requestAnother(Message msg)
	{
		String str = arrayToString(msg.msg);
		//        System.out.print("client requestAnother begin ...");
		int flag = JOptionPane.showConfirmDialog(null,
			"Player " + str + " want to play with you\nAre you OK?",
			"Play request...", JOptionPane.YES_NO_OPTION,
			JOptionPane.QUESTION_MESSAGE);
		if (flag == 0)
		{// ȷ��
			msg.type = 5; //ͬ������
			if (msg.color == 1)
			{ // msg.colorΪB����ɫ 
				drawChess(msg.color);
				jrbBlack.setSelected(true);
				jrbWhite.setSelected(false);
				bpanel.setColor(1);
			}
			else{
				drawChess(msg.color);
				jrbWhite.setSelected(true);
				jrbBlack.setSelected(false);
				bpanel.setColor(2);
			}
			//                System.out.println("B's color is"+msg.color);
			list.setEnabled(false);
			label3.setText(str);
			setting.setEnabled(false);
			jrbBlack.setEnabled(false);
			jrbWhite.setEnabled(false);
			beginFlag = true;
		}
		if (flag == 1)
		{//�ܾ�����
			msg.type = 4;
		}
		try{
			out.writeObject(msg);
		}
		catch (IOException e)
		{
			e.printStackTrace();
		}
	}
	public void paint(Graphics g)
	{
		super.paint(g);
		drawChess(bpanel.getColor());
	}
	/**
	* ��WINDOWS�ر�ʱ���˳�
	*/
	protected void processWindowEvent(WindowEvent e)
	{
		super.processWindowEvent(e);
		if (e.getID() == WindowEvent.WINDOW_CLOSING)
		{
			System.exit(0);
		}
	}
	//���ַ���ת�������鲢��'\0'����
	public void strToCharArray(String str, char[] arr)
	{
		int i;
		for (i = 0; i<str.length() && i<49; i++)
		{
			arr[i] = str.charAt(i);
		}
		arr[i] = '\0';
	}
	/**
	* �������ĩ�˹��˺����λ��
	* arr
	*  str
	*/
	public String arrayToString(char[] arr)
	{
		int i = 0, length = 0;
		while (arr[i] != '\0' && i<50)
		{
			i++;
		}
		length = i;
		char[] ss = new char[length];
		for (i = 0; i<length; i++)
		{
			ss[i] = arr[i];
		}
		String str = new String(ss);
		return str;
		//System.out.println("arraytoString "+str+"length = "+length);
	}
	/**
	* �˺͵��Զ�ս
	*/
	public void ptoComputer()
	{
		int x = 0, y = 0;
		int position;
		if (pFirst == false)
		{
			x = 7;
			y = 7;
			bpanel.updateBoard(x, y);
			bpanel.drawChess(x, y);
			beginFlag = true;
		}
		else{
			beginFlag = true;
		}
	}
	/**
	* ѡ�����ŵ�λ������
	*/
	private void cPutChess(int x, int y)
	{
		setRect(x, y);
		setWeight(x, y, pColor);
		getBetter(3);
	}
	/**
	* 9*9����
	*/
	private void setRect(int x, int y)
	{
		if (x - 4>0)  RectX1 = x - 4;
		else       RectX1 = 0;
		if (x + 4>14) RectX2 = 14;
		else       RectX2 = x + 4;
		if (y - 4>0)  RectY1 = y - 4;
		else       RectY1 = 0;
		if (y + 4>14) RectY2 = 14;
		else       RectY2 = y + 4;
		if (RectX1>RectY1) RectX1 = x - (y - RectY1);
		else              RectY1 = y - (x - RectX1);
		if (RectX2>RectY2) RectY2 = y + (RectX2 - x);
		else              RectX2 = x + (RectY2 - y);
	}
	/**
	* �ڷ�Χ���趨������Ҫ��
	*/
	private void setWeight(int x, int y, int tcolor)
	{
		int i = RectX1, j = RectY1, value = 0, k = 0, n = 0, flag = 0;
		// '--' ����
		for (i = RectX1, j = y; i <= RectX2; i++)
		{
			if (BoardPanel.board[i][j] != 0)
			{
				continue;
			}
			value = 0; flag = 0;
			for (k = 1; i - k >= RectX1 && k<5; k++)
			{
				if (BoardPanel.board[i - k][j] == tcolor)
				{
					value++;
					continue;
				}
				if (BoardPanel.board[i - k][j] == 0)
				{//black space
					flag++;
					break;
				}
			}
			for (k = 1; i + k<RectX2 && k<5; k++)
			{
				if (BoardPanel.board[i + k][j] == tcolor)
				{
					value++;
				}
				if (BoardPanel.board[i + k][j] == 0)
				{
					flag++;
					break;
				}
			}
			n = weight(value, flag);
			if (weightBoard[i][j]<n)
			{
				weightBoard[i][j] = n;
			}
		}
		// '|' ����
		for (i = x, j = RectY1; j <= RectY2; j++)
		{
			if (BoardPanel.board[i][j] != 0)
			{
				continue;
			}
			value = 0; flag = 0;
			for (k = 1; j - k >= RectY1 && k<5; k++)
			{
				if (BoardPanel.board[i][j - k] == tcolor)
				{
					value++;
					continue;
				}
				if (BoardPanel.board[i][j - k] == 0)
				{
					flag++;
					break;
				}
			}
			for (k = 1; j + k<RectY2 && k<5; k++)
			{
				if (BoardPanel.board[i][j + k] == tcolor)
				{
					value++;
				}
				if (BoardPanel.board[i][j + k] == 0)
				{
					flag++;
					break;
				}
			}
			n = weight(value, flag);
			if (weightBoard[i][j]<n)
			{
				weightBoard[i][j] = n;
			}
		}
		// '\' ����
		for (i = RectX1, j = RectY1; i <= RectX2; i++, j++)
		{
			if (BoardPanel.board[i][j] != 0)
			{
				continue;
			}
			value = 0; flag = 0;
			for (k = 1; i - k >= RectX1 && k<5; k++)
			{
				if (BoardPanel.board[i - k][j - k] == tcolor)
				{
					value++;
					continue;
				}
				if (BoardPanel.board[i - k][j - k] == 0)
				{
					flag++;
					break;
				}
			}
			for (k = 1; i + k<RectX2 && k<5; k++)
			{
				if (BoardPanel.board[i + k][j + k] == tcolor)
				{
					value++;
				}
				if (BoardPanel.board[i + k][j + k] == 0)
				{
					flag++;
					break;
				}
			}
			n = weight(value, flag);
			if (weightBoard[i][j]<n)
			{
				weightBoard[i][j] = n;
			}
		}
		// '/' ����
		for (i = RectX2, j = RectY1; i >= RectX1; i--, j++)
		{
			if (BoardPanel.board[i][j] != 0)
			{
				continue;
			}
			value = 0; flag = 0;
			for (k = 1; i + k <= RectX2 && k<5; k++)
			{
				if (BoardPanel.board[i + k][j - k] == tcolor)
				{
					value++;
					continue;
				}
				if (BoardPanel.board[i + k][j - k] == 0)
				{
					flag++;
					break;
				}
			}
			for (k = 1; i - k >= RectX1 && k<5; k++)
			{
				if (BoardPanel.board[i - k][j + k] == tcolor)
				{
					value++;
				}
				if (BoardPanel.board[i - k][j + k] == 0)
				{
					flag++;
					break;
				}
			}
			n = weight(value, flag);
			if (weightBoard[i][j]<n)
			{
				weightBoard[i][j] = n;
			}
		}
	}
	/**
	* ��������ֵ
	*count
	*flag
	*/
	private int weight(int count, int flag)
	{
		int weight = 0;
		switch (count)
		{
		case 0:{
				   if (flag>0) weight = 200;
				   else weight = 0;
				   break;
		}
		case 1:{
				   if (flag>0) weight = 1000;
				   else weight = 0;
				   break;
		}
		case 2:{
				   if (flag>0) weight = 5000;
				   else weight = 0;
				   break;
		}
		case 3:{
				   if (flag>0) weight = 8000;
				   else weight = 0;
				   break;
		}
		case 4:{
				   if (flag>0) weight = 10000;
				   else weight = 0;
				   break;
		}
		}
		return weight;
	}
	/**
	* ������������ҵ����õļ���λ�ã�Ĭ��ֵΪ3
	*/
	private void getBetter(int count)
	{
		int[][] better = new int[count][2];
		int[][] tempArray = new int[15][15];
		for (int i = 0; i<15; i++)
		{
			for (int j = 0; j<15; j++)
			{
				tempArray[i][j] = weightBoard[i][j];
			}
		}
		for (int i = 0; i<count; i++)
		{
			getBiggest(tempArray, better[i][0], better[i][1]);
		}
		bestX = better[0][0]; bestY = better[0][1];
	}
	/**
	*  arr
	*  x
	*  y
	*/
	private void getBiggest(int[][] arr, int x, int y)
	{
		int[] temp = new int[2];
		int swt = arr[0][0], tmp = 0;
		for (int i = 0; i<15; i++)
		{
			for (int j = 0; j<15; j++)
			{
				if (arr[i][j]>swt)
				{
					temp[0] = i; temp[1] = j;
					swt = arr[i][j];
				}
			}
		}
		x = temp[0];
		y = temp[1];
		arr[x][y] = 0;
	}


}