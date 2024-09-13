#pretty secure $page = $_GET["page"];
include($page.".php"); #it basically prevents any inclusion aside than file with PHP format
# this is for a challenge root me (RFI) Remote local file inclusion, so i need a public link create by your website
