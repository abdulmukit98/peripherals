UUID

    UUID.fromString("00001101-0000-1000-8000-00805F9B34FB");
  
  
    BluetoothAdapter bluetoothAdapter = BluetoothAdapter.getDefaultAdapter();
    System.out.println(bluetoothAdapter.getBondedDevices());    <set of BluetoothDeevice>
  
    BluetoothDevice hc05 = bluetoothAdapter.getRemoteDevice("00:21:13:02:B0:63");
    System.out.println(hc05.getName());

  
### Connect

    try {
            bluetoothSocket = hc05.createRfcommSocketToServiceRecord(bUUID);
            System.out.println(bluetoothSocket);
            bluetoothSocket.connect();
            System.out.println("Connected on? " + bluetoothSocket.isConnected());
        } catch (IOException e) {
            e.printStackTrace();
        }
  
  ### Disconnect
    
    try {
            bluetoothSocket.close();
            System.out.println("closed? " + bluetoothSocket.isConnected());
        } catch (IOException e) {
            e.printStackTrace();
        }
  
  ### send data
  
    OutputStream outputStream;
    try {
            outputStream = bluetoothSocket.getOutputStream();
            outputStream.write((byte) '1');
        } catch (IOException e) {
            e.printStackTrace();
        }
