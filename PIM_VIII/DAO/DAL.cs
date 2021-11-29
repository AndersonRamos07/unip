using System;
using System.Data;
using Npgsql;
using PIM_VIII.Models;

namespace PIM_VIII
{
static string serverName = "127.0.0.1";
static string port = "5432";
static string userName = "postgres";
static string password = "805376";
static string databaseName = "pimviii";
private NpgsqlConnection pgsqlConnection = null;
string connString = null;

public DAL()
{
    connString = String.Format("Server={0};Port={1};User Id={2};Password={3};Database={4};",
        serverName, port, userName, password, databaseName);
}
#region PegarTodosRegistros   

public DataTable GetTodosRegistros()
{
    DataTable dt = new DataTable();
    try
    {
        using(pgsqlConnection = new NpgsqlConnection(connString))
        {
            pgsqlConnection.Open();
            string cmdSelecionda = "SELECT * FROM PESSOAS ORDER BY ID";

            using(NpgsqlDataAdapter Adpt = new NpgsqlDataAdapter(cmdSelecionda, pgsqlConnection))
            {
                Adpt.Fill(dt);
            }
        }
    }
    catch (NpgsqlException ex){
        throw ex;
    }
    catch (Exception ex)
    {
        throw ex;
    }
    finally
    {
        pgsqlConnection.Close();
    }
    return dt;
}

#endregion

#region PegarRegistrosPorId

public DataTable GetRegistroPorId(int id)
{
    DataTable dt = new DataTable();

    try
    {
        using (NpgsqlConnection pgsqlConnection = new NpgsqlConnection(connString))
        {
            pgsqlConnection.Open();
            string cmdSeleciona = "SELECT * FROM PESSOAS WHERE ID = " + id;

            using(NpgsqlDataAdapter Adpt = new NpgsqlDataAdapter(cmdSeleciona, pgsqlConnection))
            {
                Adpt.Fill(dt);
            }
        }
    }
    catch (NpgsqlException ex)
    {
        throw ex;
    }
    catch (Exception ex)
    {
        throw ex;
    }
    finally
    {
        pgsqlConnection.Close();
    }
    return dt;
}

#endregion

#region InserirRegistros

public void InserirRegistros(Pessoa pessoa)
{
    try
    {
        using(NpgsqlConnection pgsqlConnection = new NpgsqlConnection(connString))
        {
            pgsqlConnection.Open();
            string cmdInserir = String.Format("INSERT INTO PESSOAS() VALUES ('{0}', '{1}', '{2}')", pessoa.Nome, pessoa.CPF, pessoa.Endereco);
            using(NpgsqlCommand pgsqlcommand = new NpgsqlCommand(cmdInserir, pgsqlConnection))
            {
                pgsqlcommand.ExecuteNonQuery();
            }
        }
    }
    catch (NpgsqlException ex)
    {
        throw ex;
    }
    catch (Exception ex)
    {
        throw ex;
    }
    finally
    {
        pgsqlConnection.Close();
    }
}

#endregion

#region AtualizarRegistros

public void AtualizarRegistro(int id, Pessoa pessoa)
{
    try
    {
        using (NpgsqlConnection pgsqlConnection = new NpgsqlConnection(connString))
        {
            //Abra a conexão com o PgSQL                  
            pgsqlConnection.Open();

            string cmdAtualiza = String.Format("UPDATE PESSOAS SET Nome = '"  + pessoa.Nome + "' , CPF = " + pessoa.CPF + " Where id = " + id);

            using (NpgsqlCommand pgsqlcommand = new NpgsqlCommand(cmdAtualiza, pgsqlConnection))
            {
                pgsqlcommand.ExecuteNonQuery();
            }
        }
    }
    catch (NpgsqlException ex)
    {
        throw ex;
    }
    catch (Exception ex)
    {
        throw ex;
    }
    finally
    {
        pgsqlConnection.Close();
    }
}

#endregion

#region DeletarRegistros
public void DeletarRegistro(int id)
{
    try
    {
        using (NpgsqlConnection pgsqlConnection = new NpgsqlConnection(connString))
        {
            //abre a conexao                
            pgsqlConnection.Open();

            string cmdDeletar = String.Format("DELETE FROM PESSOAS WHERE ID = '{0}'",id);

            using (NpgsqlCommand pgsqlcommand = new NpgsqlCommand(cmdDeletar, pgsqlConnection))
            {
                pgsqlcommand.ExecuteNonQuery();
            }
        }
    }
    catch (NpgsqlException ex)
    {
        throw ex;
    }
    catch (Exception ex)
    {
        throw ex;
    }
    finally
    {
        pgsqlConnection.Close();
    }
}
#endregion
}