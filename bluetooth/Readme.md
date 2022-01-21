UUID

    UUID.fromString("00001101-0000-1000-8000-00805F9B34FB");
  
### Initialize 

    BluetoothAdapter bluetoothAdapter = BluetoothAdapter.getDefaultAdapter();
    System.out.println(bluetoothAdapter.getBondedDevices());    <set of BluetoothDeevice>
  
    BluetoothDevice hc05 = bluetoothAdapter.getRemoteDevice("00:21:13:02:B0:63");
    System.out.println(hc05.getName());

  
### Connect
bluetoothSocket = **BluetoothDevice**.createRfcommSocketToServiceRecord(**UUID**);

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

    //
    String cmd
    outputStream.write(cmd.getBytes());
    
    

### receive data
* use a background thread to scan for data 
* in the run() method 

```
InputStream inputStream;
/**
 *  Continuously scan for data while device is connected.
 */
while(socket.isConnected())
{
    try
    {
        inputStram = socket.getInputStream();
        byte[] buffer = new byte[1024];
        if(inputStream.available() > 0)
        {
            inputStream.read(buffer);       // store data in buffer
            int i = 0;                      // global i
            for(i = 0; i < buffer.length && buffer[i] != 0; i++)
            {
            }
            String message = new String(buffer, 0, i);
            System.out.println(message);
        }
        sleep(500);
    }
    catch ()
    {
    }
}
```

### Turn on bluetooth
```
while(!bluetootheAdapter.isEnabled())
{
    Intent intent = new Intent(bluetoothAdapter.ACTION_REQUEST_ENABLE);
    startActivityForResult(intent, 1);
}
```
