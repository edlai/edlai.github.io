<!doctype html>
<html lang="en">
 <head>
  <meta charset="UTF-8">
  <meta name="Generator" content="">
  <meta name="Author" content="">
  <meta name="Keywords" content="">
  <meta name="Description" content="">
  <title>APN</title>
  
  <script type="text/javascript">
  <!--
  //self.opener.location.reload();
  
  }
  //-->
  </script>
  
 </head>
 <body>

 World-Wide Cellular APN Table (from android phone) v1.1

 <form method="post" action="<?=$_SERVER['PHP_SELF'];?>">

<table style="border:3px #cccccc solid;" cellpadding="10" border='1'>
<tr>
	<th>Field</th>
 	<th>Value</th>
</tr>
<tr>
	<td>
	 MCC
	</td>
	<td>
   <input type="text" name="mcc"> (optional)
	</td>
 </tr>
<tr>
	<td>
	 MNC
	</td>
	<td>
    <input type="text" name="mnc"> (optional)
	</td>
 </tr>

 <tr>
 	<td>
	 Protocol Type
	</td>
  <td>
    <select name="protocol">
    <option value="na" selected> N/A </option>
	  <option value="ipv4"> IPv4 only</option>
	  <option value="ipv4v6"> IPv4v6 DualStack </option>
    </select>  (optional)
	</td>
</tr>
<tr>
 	<td>
	 Export to
	</td>
	<td>
	  <select name="">
      <option value="html" selected> HTML </option>
	    <option value="csv"> CSV </option>
	    <option value="json"> JSON </option>
      <option value="xml">  XML </option>
    </select> 
	</td>
</tr>

<tr>
 	<td>

	</td>
	<td>
    <input type="reset">
	  <input type="submit" name="Submit"/>
	</td>
</tr>

</table>
</form>

<?php
if(isset($_POST['Submit']))
{
    
    echo "<hr>";
    echo "You are searching for ";
    //echo "<!--";
    echo "&nbsp; MCC: &nbsp;";
    echo ($_POST["mcc"]);
    echo "&nbsp; MNC: &nbsp;";
    echo ($_POST["mnc"]);
    //echo "-->";
    echo "</p>";
        
    // Read cats.xml and print the results:
    if (file_exists('apns.xml')) 
    {
      $apns = simplexml_load_file('apns.xml');     
      #print_r($apns);
      echo "<table style='border:3px #cccccc solid;' cellpadding='10' border='1'>";
      
      
      printf("<tr><th>#ID</th><th>Carrier</th><th>MCC</th><th>MNC</th><th>APN</th>        \n");
      printf("    <th>Type</th><th>Protocol</th><th>Roaming Protocol</th></tr>\n");
      $id = 0;
      foreach ($apns->apn as $apn) 
      {
        if (empty($_POST["mcc"]) && empty($_POST["mnc"]))
        {
          echo "<tr>";
          printf("<td>%d</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td>\n", 
          $id++,
          $apn["carrier"],
          $apn["mcc"],
          $apn["mnc"],
	        $apn["apn"],
          $apn["type"],
          $apn["protocol"],
          $apn["roaming_protocol"]);
          echo "</tr>";
        }
        else if (strcmp($_POST["mcc"],$apn["mcc"]) == 0 &&
            strcmp($_POST["mnc"],$apn["mnc"]) == 0)
        {
          echo "<tr>";
          printf("<td>%d</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td>\n", 
          $id++,
          $apn["carrier"],
          $apn["mcc"],
          $apn["mnc"],
	        $apn["apn"],
          $apn["type"],
          $apn["protocol"],
          $apn["roaming_protocol"]);
          echo "</tr>";
        }
      }
      echo "</table>";
    } 
    else 
    {
	    exit('Failed to open apns.xml.');
    }
  }
?>	
  
 </body>
</html>
